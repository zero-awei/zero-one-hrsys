package com.zeroone.star.oauth2.controller;

import com.nimbusds.jose.jwk.JWKSet;
import com.nimbusds.jose.jwk.RSAKey;
import com.zeroone.star.project.oauth.KeyPairApis;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.security.KeyPair;
import java.security.interfaces.RSAPublicKey;
import java.util.Map;

/**
 * <p>
 * 描述：获取RSA密钥接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
@RestController
@RequestMapping("rsa")
public class KeyPairController implements KeyPairApis {
    private final KeyPair keyPair;

    @Autowired
    public KeyPairController(KeyPair keyPair) {
        this.keyPair = keyPair;
    }

    @Override
    @GetMapping("public-key")
    public Map<String, Object> getPublicKey() {
        RSAPublicKey publicKey = (RSAPublicKey) keyPair.getPublic();
        RSAKey key = new RSAKey.Builder(publicKey).build();
        return new JWKSet(key).toJSONObject();
    }

    @Override
    @GetMapping("private-key")
    public Map<String, Object> getPrivateKey() {
        return null;
    }
}
