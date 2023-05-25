package com.zeroone.star.login.controller;

import cn.hutool.core.bean.BeanUtil;
import com.anji.captcha.model.common.ResponseModel;
import com.anji.captcha.model.vo.CaptchaVO;
import com.anji.captcha.service.CaptchaService;
import com.zeroone.star.login.service.IMenuService;
import com.zeroone.star.login.service.IUserService;
import com.zeroone.star.login.service.OauthService;
import com.zeroone.star.login.utils.RedisUtils;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.constant.AuthConstant;
import com.zeroone.star.project.constant.RedisConstant;
import com.zeroone.star.project.dto.login.LoginDTO;
import com.zeroone.star.project.dto.login.Oauth2TokenDTO;
import com.zeroone.star.project.login.LoginApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.login.LoginVO;
import com.zeroone.star.project.vo.login.MenuTreeVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.concurrent.TimeUnit;

import static com.zeroone.star.project.vo.JsonVO.fail;

/**
 * <p>
 * 描述：登录接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
@RestController
@RequestMapping("login")
@Api(tags = "login")
@Slf4j
public class LoginController implements LoginApis {

    @Resource
    OauthService oAuthService;
    @Resource
    UserHolder userHolder;
    @Resource
    IUserService userService;
    @Resource
    RedisUtils redisUtils;
    @Resource
    CaptchaService captchaService;
    @Autowired
    PasswordEncoder passwordEncoder;

    @ApiOperation(value = "授权登录")
    @PostMapping("auth-login")
    @Override
    public JsonVO<Oauth2TokenDTO> authLogin(LoginDTO loginDTO) {
        //1.验证码验证
        CaptchaVO captchaVO = new CaptchaVO();
        captchaVO.setCaptchaVerification(loginDTO.getCode());
        ResponseModel response = captchaService.verification(captchaVO);
        if (!response.isSuccess()) {
            JsonVO<Oauth2TokenDTO> fail = fail(null);
            fail.setMessage(response.getRepCode() + response.getRepMsg());
            //验证码校验失败，返回信息告诉前端
            //repCode  0000  无异常，代表成功
            //repCode  9999  服务器内部异常
            //repCode  0011  参数不能为空
            //repCode  6110  验证码已失效，请重新获取
            //repCode  6111  验证失败
            //repCode  6112  获取验证码失败,请联系管理员
            return fail;
        }
        //2.账号密码认证
        Map<String, String> params = new HashMap<>(5);
        params.put("grant_type", "password");
        params.put("client_id", loginDTO.getClientId());
        params.put("client_secret", AuthConstant.CLIENT_PASSWORD);
        params.put("username", loginDTO.getUsername());
        params.put("password", loginDTO.getPassword());
        //3.调用远程接口，获取Token
        JsonVO<Oauth2TokenDTO> oauth2TokenDTO = oAuthService.postAccessToken(params);
        //4.将授权token存储到Redis中，记录登录状态
        //4.1拼接key
        String userTokenKey = RedisConstant.USER_TOKEN + ":" + oauth2TokenDTO.getData().getToken();
        //4.2逻辑判断
        if (redisUtils.add(userTokenKey, 1, 1L, TimeUnit.HOURS) < 0) {
            return fail(oauth2TokenDTO.getData(), ResultStatus.SERVER_ERROR);
        }
        //返回结果token
        return oauth2TokenDTO;
    }

    @ApiOperation(value = "刷新登录")
    @PostMapping("refresh-token")
    @Override
    public JsonVO<Oauth2TokenDTO> refreshToken(Oauth2TokenDTO oauth2TokenDTO) {
        //1.判断缓存中是否存在对应token
        String tokenKeyInRedis = RedisConstant.USER_TOKEN + ":" + oauth2TokenDTO.getToken();
        if (!redisUtils.isExist(tokenKeyInRedis)) {
            //不存在
            return fail(null, ResultStatus.UNAUTHORIZED);
        }
        //存在
        //2.封装参数
        Map<String, String> params = new HashMap<>(4);
        params.put("grant_type", "refresh_token");
        params.put("client_id", oauth2TokenDTO.getClientId());
        params.put("client_secret", AuthConstant.CLIENT_PASSWORD);
        params.put("refresh_token", oauth2TokenDTO.getRefreshToken());
        // 3.再次调用远程接口获取新token
        JsonVO<Oauth2TokenDTO> refreshedTokenDTO = oAuthService.postAccessToken(params);
        // 4.检查新token
        log.info("oAuthService.postAccessToken required data: {}", refreshedTokenDTO.getData().getToken());
        // 5.用新token更新Redis中的旧token
        String refreshedTokenKey = RedisConstant.USER_TOKEN + ":" + refreshedTokenDTO.getData().getToken();
        if (redisUtils.add(refreshedTokenKey, 1, 1L, TimeUnit.HOURS) < 0) {
            //添加key失败
            return fail(null, ResultStatus.SERVER_BUSY);
        }
        // 6.删除Redis中原有的token
        if (redisUtils.del(tokenKeyInRedis) < 0) {
            //删除失败
            return fail(null, ResultStatus.SERVER_BUSY);
        }
        // 7.返回新token
        return refreshedTokenDTO;
    }

    @ApiOperation(value = "获取当前用户")
    @GetMapping("current-user")
    @Override
    public JsonVO<LoginVO> getCurrUser() {
        UserDTO currentUser;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), e.getMessage());
        }
        if (currentUser == null) {
            return fail(null);
        } else {
            //TODO:这里需要根据业务逻辑接口，重新实现
            LoginVO vo = new LoginVO();
            BeanUtil.copyProperties(currentUser, vo);
            return JsonVO.success(vo);
        }
    }

    @ApiOperation(value = "退出登录")
    @GetMapping("logout")
    @Override
    public JsonVO<String> logout() {
        //TODO:登出逻辑，需要配合登录逻辑实现
        //1.获取当前用户token
        //2.删除当前用户token
        return null;
    }

    @Resource
    IMenuService menuService;

    @ApiOperation(value = "获取菜单")
    @GetMapping("get-menus")
    @Override
    public JsonVO<List<MenuTreeVO>> getMenus() throws Exception {
        //TODO:未实现根据实际数据库设计业务逻辑，下面逻辑属于示例逻辑
        //1 获取当前用户
        UserDTO currentUser = userHolder.getCurrentUser();
        //2 获取当前用户拥有的菜单
        List<MenuTreeVO> menus = menuService.listMenuByRoleName(currentUser.getRoles());
        return JsonVO.success(menus);
    }


    @SneakyThrows
    @ApiOperation(value = "修改密码")
    @PostMapping("update-password")
    @Override
    public JsonVO<String> updatePassword(LoginDTO loginDTO) {
        //1.获取新密码
        String newPassword = loginDTO.getPassword();
        //2.获取用户名
        String userName = loginDTO.getUsername();
        //3.获取旧密码
        String oldPassword = userService.getCurrentPassword(userName);
        //4.判断新旧密码是否一致
        boolean matches = passwordEncoder.matches(oldPassword, newPassword);
        if (matches) {
            return JsonVO.fail("新旧密码不能一致！");
        }
        //5.修改密码
        Boolean isSuccess = userService.updatePassword(userName, oldPassword);
        //6.返回结果
        if (!isSuccess) {
            //更新失败
            return JsonVO.fail("密码修改失败");
        }
        return JsonVO.success("密码修改成功");

    }
}
