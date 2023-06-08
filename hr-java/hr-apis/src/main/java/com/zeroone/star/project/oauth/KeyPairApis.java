package com.zeroone.star.project.oauth;

import java.util.Map;

/**
 * <p>
 * 描述：密钥接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
public interface KeyPairApis {
    /**
     * 获取公钥
     * @return 返回公钥数据
     */
    Map<String, Object> getPublicKey();

    /**
     * 获取私钥
     * @return 返回私钥数据
     */
    Map<String, Object> getPrivateKey();
}
