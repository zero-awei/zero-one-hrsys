package com.zeroone.star.project.login;

import com.zeroone.star.project.dto.login.LoginDTO;
import com.zeroone.star.project.dto.login.Oauth2TokenDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.login.LoginVO;
import com.zeroone.star.project.vo.login.MenuTreeVO;

import java.util.List;

/**
 * <p>
 * 描述：用户登录接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
public interface LoginApis {
    /**
     * 授权登录接口
     * @param loginDTO 登录数据
     * @return 授权登录结果
     */
    JsonVO<Oauth2TokenDTO> authLogin(LoginDTO loginDTO);

    /**
     * 刷新Token认证
     * @param oauth2TokenDTO Token数据对象
     * @return 刷新Token结果
     */
    JsonVO<Oauth2TokenDTO> refreshToken(Oauth2TokenDTO oauth2TokenDTO);

    /**
     * 获取当前用户信息
     * @return 返回当前用户信息
     */
    JsonVO<LoginVO> getCurrUser();

    /**
     * 退出登录
     * @return 退出结果
     */
    JsonVO<String> logout() throws Exception;

    /**
     * 获取菜单数据
     * @return 菜单数据
     * @throws Exception 异常信息
     */
    JsonVO<List<MenuTreeVO>> getMenus() throws Exception;

    /***
     * 修改密码
     * @param loginDTO
     * @return 修改成功or失败信息
     */
    JsonVO<String> updatePassword(LoginDTO loginDTO);
}
