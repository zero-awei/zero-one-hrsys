package com.zeroone.star.project.components.user;

import cn.hutool.core.convert.Convert;
import cn.hutool.json.JSONObject;
import com.zeroone.star.project.components.jwt.JwtComponent;
import org.springframework.stereotype.Component;
import org.springframework.web.context.request.RequestContextHolder;
import org.springframework.web.context.request.ServletRequestAttributes;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletRequest;

/**
 * <p>
 * 描述：获取登录用户信息
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
@Component
public class UserHolder {
    @Resource
    JwtComponent jwtComponent;

    /**
     * 从请求头中获取用户信息
     *
     * @return 用户信息
     * @throws Exception 解析失败抛出异常
     */
    @SuppressWarnings("MismatchedQueryAndUpdateOfCollection")
    public UserDTO getCurrentUser() throws Exception {
        //从Header中获取用户信息
        ServletRequestAttributes servletRequestAttributes = (ServletRequestAttributes) RequestContextHolder.getRequestAttributes();
        if (servletRequestAttributes == null) {
            return null;
        }
        HttpServletRequest request = servletRequestAttributes.getRequest();
        String userStr = request.getHeader("user");
        //不是通过网关过来的，那么执行解析验证JWT
        if (userStr == null) {
            //从token中解析用户信息并设置到Header中去
            String realToken = request.getHeader("Authorization").replace("Bearer ", "");
            userStr = jwtComponent.defaultRsaVerify(realToken);
        }
        JSONObject userJsonObject = new JSONObject(userStr);
        return UserDTO.builder()
                .id(Convert.toStr(userJsonObject.get("id")))
                .username(userJsonObject.getStr("user_name"))
                .isEnabled(Convert.toByte(1))
                .roles(Convert.toList(String.class, userJsonObject.get("authorities")))
                .build();
    }

    /**
     * 获取当前用户的token
     *
     * @return token
     */
    public String getCurrentUserToken() {
        //从Header中获取用户信息
        ServletRequestAttributes servletRequestAttributes = (ServletRequestAttributes) RequestContextHolder.getRequestAttributes();
        if (servletRequestAttributes == null) {
            return null;
        }
        HttpServletRequest request = servletRequestAttributes.getRequest();
        return request.getHeader("Authorization").replace("Bearer ", "");

    }
}
