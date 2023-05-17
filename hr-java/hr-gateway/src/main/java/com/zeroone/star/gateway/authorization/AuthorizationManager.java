package com.zeroone.star.gateway.authorization;

import cn.hutool.core.convert.Convert;
import com.zeroone.star.project.constant.AuthConstant;
import com.zeroone.star.project.constant.RedisConstant;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.cloud.context.config.annotation.RefreshScope;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.security.authorization.AuthorizationDecision;
import org.springframework.security.authorization.ReactiveAuthorizationManager;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.web.server.authorization.AuthorizationContext;
import org.springframework.stereotype.Component;
import reactor.core.publisher.Mono;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

/**
 * <p>
 * 描述：鉴权管理器，用于判断是否有资源的访问权限
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
@RefreshScope
@Component
public class AuthorizationManager implements ReactiveAuthorizationManager<AuthorizationContext> {
    @Resource
    private RedisTemplate<String, Object> redisTemplate;

    @Value("${secure.openauthorization}")
    private boolean isOpenAuthorization;

    /**
     * 通过路径查询角色列表
     * @param path 路径名
     * @return 没有查询到返回空列表
     */
    private List<String> queryRoleListByPath(String path) {
        Object obj = redisTemplate.opsForHash().get(RedisConstant.RESOURCE_ROLES_MAP, path);
        if (obj == null) {
            return new ArrayList<>();
        }
        List<String> authorities = Convert.toList(String.class, obj);
        authorities = authorities.stream().map(roleName -> roleName = AuthConstant.AUTHORITY_PREFIX + roleName).collect(Collectors.toList());
        return authorities;
    }

    @Override
    public Mono<AuthorizationDecision> check(Mono<Authentication> mono, AuthorizationContext authorizationContext) {
        //如果关闭鉴权功能，直接放行
        if (!isOpenAuthorization) {
            return Mono.just(new AuthorizationDecision(true));
        }

        //1 从Redis中获取当前路径可访问角色列表
        String path = authorizationContext.getExchange().getRequest().getURI().getPath();
        List<String> authorities = queryRoleListByPath(path);
        // 没有查询到结果，尝试查找通配符
        if (authorities.isEmpty()) {
            // 1.1 处理二级地址, 比如：请求地址为 "/fc/get"，此时匹配 "/fc/**"
            String[] arr = path.split("/");
            String currPath = "/" + arr[1] + "/**";
            authorities = queryRoleListByPath(currPath);
            // 1.2 处理参数变量，比如请求地址为 "/fc/get/参数变量"，此时匹配 "/fc/get/**"
            if (authorities.isEmpty()) {
                currPath = path.substring(0, path.lastIndexOf("/") + 1) + "**";
                authorities = queryRoleListByPath(currPath);
            }
        }

        //2 认证通过且角色匹配的用户可访问当前路径
        return mono
                // 判断是否认证
                .filter(Authentication::isAuthenticated)
                // 获取权限对象列表(即：角色列表)
                .flatMapIterable(Authentication::getAuthorities)
                // 遍历获取权限对象(即：获取单个角色名)
                .map(GrantedAuthority::getAuthority)
                // 查看当前路径中是否包对应权限（即：是否包含角色名）
                .any(authorities::contains)
                // 根据判断结果构建一个鉴权对象
                .map(AuthorizationDecision::new)
                // 没有权限列表的情况，构建一个无权访问对象
                .defaultIfEmpty(new AuthorizationDecision(false));
    }
}
