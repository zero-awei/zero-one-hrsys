package com.zeroone.star.project.constant;

/**
 * <p>
 * 描述：授权相关常量
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
public interface AuthConstant {
    /**
     * JWT存储权限前缀
     */
    String AUTHORITY_PREFIX = "ROLE_";

    /**
     * JWT存储权限属性
     */
    String AUTHORITY_CLAIM_NAME = "authorities";

    /**
     * app端客户端类型定义
     */
    String CLIENT_APP = "hr-app";

    /**
     * 管理端客户端类型定义
     */
    String CLIENT_MANAGER = "hr-manager";

    /**
     * 客户端密码
     */
    String CLIENT_PASSWORD = "123456";
}
