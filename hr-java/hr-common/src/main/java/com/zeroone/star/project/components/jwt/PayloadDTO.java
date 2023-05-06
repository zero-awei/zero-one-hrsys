package com.zeroone.star.project.components.jwt;

import lombok.Builder;
import lombok.Data;

import java.util.List;

/**
 * <p>
 * 描述：负载数据对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
@Data
@Builder
public class PayloadDTO {
    /**
     * 主体数据
     */
    private String sub;
    /**
     * 过期时间
     */
    private Long exp;
    /**
     * 用户名称
     */
    private String username;
    /**
     * 用户拥有的权限
     */
    private List<String> authorities;
}
