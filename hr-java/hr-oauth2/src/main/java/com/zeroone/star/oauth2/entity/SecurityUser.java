package com.zeroone.star.oauth2.entity;

import lombok.Getter;
import lombok.Setter;
import lombok.ToString;
import org.springframework.security.core.GrantedAuthority;

import java.util.Collection;

/**
 * <p>
 * 描述：权限认证用户实体
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
@Getter
@Setter
@ToString
public class SecurityUser extends org.springframework.security.core.userdetails.User {
    /**
     * 关联一个用户对象
     */
    private User user;

    /**
     * 构造初始化
     *
     * @param user        数据库的User对象
     * @param authorities 权限列表
     */
    public SecurityUser(User user, Collection<? extends GrantedAuthority> authorities) {
        super(user.getUsername(), user.getPassword(), authorities);
        this.user = user;
    }
}
