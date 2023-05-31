package com.zeroone.star.oauth2.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.oauth2.entity.Role;
import com.zeroone.star.oauth2.entity.SecurityUser;
import com.zeroone.star.oauth2.entity.User;
import com.zeroone.star.oauth2.service.IRoleService;
import com.zeroone.star.oauth2.service.IUserService;
import com.zeroone.star.project.constant.AuthConstant;
import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.core.authority.SimpleGrantedAuthority;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletRequest;
import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 描述：用户权限权限服务实现
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
@Service
public class UserDetailsServiceImpl implements UserDetailsService {
    @Resource
    IUserService userService;
    @Resource
    IRoleService roleService;
    @Resource
    HttpServletRequest request;

    @Override
    public UserDetails loadUserByUsername(String username) throws UsernameNotFoundException {
        String clientId = request.getParameter("client_id");
        if (AuthConstant.CLIENT_MANAGER.equals(clientId)) {
            //1 通过用户名查找用户对象
            User user = new User();
            user.setUsername(username);
            System.out.println("userService.getOne执行开始！");

            user = userService.getOne(new QueryWrapper<>(user));
            System.out.println("userService.getOne执行完毕！");
            if (user == null) {
                throw new UsernameNotFoundException("用户名或密码错误");
            }
            //2 通过用户ID获取角色列表
            System.out.println("！进入roleService.listRoleByUserId之前！");
            List<Role> roles = roleService.listRoleByUserId(user.getId());
            System.out.println("*********roles.stream().toArray() = " + roles.stream().toArray());
            //3 将数据库角色转换成Security权限对象
            List<GrantedAuthority> authorities = new ArrayList<>();
            roles.forEach(role -> authorities.add(new SimpleGrantedAuthority(role.getKeyword())));
            System.out.println("*****此时的user是" + user.getUsername() + "**" +user.getPassword());
            //4 构建权限角色对象
            return new SecurityUser(user, authorities);
        } else if (AuthConstant.CLIENT_APP.equals(clientId)) {
            throw new UsernameNotFoundException("用户端查找用户尚未实现");
        }
        throw new UsernameNotFoundException("登录客户端ID错误");
    }
}
