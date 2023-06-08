package com.zeroone.star.project.components.jwt;

import cn.hutool.core.convert.Convert;
import cn.hutool.core.date.DateUtil;
import cn.hutool.crypto.SecureUtil;
import cn.hutool.json.JSONObject;
import cn.hutool.json.JSONUtil;
import com.nimbusds.jose.*;
import com.nimbusds.jose.crypto.MACSigner;
import com.nimbusds.jose.crypto.MACVerifier;
import com.nimbusds.jose.crypto.RSASSASigner;
import com.nimbusds.jose.crypto.RSASSAVerifier;
import com.nimbusds.jose.jwk.JWK;
import com.nimbusds.jose.jwk.RSAKey;
import com.zeroone.star.project.components.jwt.exception.JwtExpiredException;
import com.zeroone.star.project.components.jwt.exception.JwtInvalidException;
import io.micrometer.core.lang.Nullable;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.core.io.Resource;
import org.springframework.stereotype.Component;
import org.springframework.util.StreamUtils;

import java.nio.charset.Charset;
import java.util.Date;
import java.util.List;

/**
 * <p>
 * 描述：JWT工具类
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
@Component
public class JwtComponent {

    /**
     * 获取默认的PayloadDto对象
     *
     * @param subject     主体内容
     * @param userName    用户名
     * @param authorities 权限列表
     * @return PayloadDto对象
     */
    public PayloadDTO getDefaultPayloadDto(String subject, String userName, List<String> authorities) {
        return getDefaultPayloadDto(subject, userName, authorities, 18000);
    }

    /**
     * 获取默认的PayloadDto对象,负载信息默认证书有效时间为18000秒
     *
     * @param subject     主体内容
     * @param userName    用户名
     * @param authorities 权限列表
     * @param expSecond   有效时间，单位秒
     * @return PayloadDto对象
     */
    public PayloadDTO getDefaultPayloadDto(String subject, String userName, List<String> authorities, int expSecond) {
        Date now = new Date();
        Date exp = DateUtil.offsetSecond(now, expSecond);
        return PayloadDTO.builder()
                .sub(subject)
                .exp(exp.getTime())
                .username(userName)
                .authorities(authorities)
                .build();
    }

    /**
     * 验证并获取负载信息
     */
    private PayloadDTO parseToPayloadDto(JWSObject jwsObject, JWSVerifier jwsVerifier) throws Exception {
        // 1 验证签名
        if (!jwsObject.verify(jwsVerifier)) {
            throw new JwtInvalidException("token签名不合法！");
        }
        // 2 获取负载信息
        String payload = jwsObject.getPayload().toString();
        PayloadDTO payloadDto = JSONUtil.toBean(payload, PayloadDTO.class);

        // 3 验证是否过期
        if (payloadDto.getExp() < System.currentTimeMillis()) {
            throw new JwtExpiredException("token已过期！");
        }

        //4 返回负载信息
        return payloadDto;
    }

    /**
     * 使用HMAC算法构建Token
     *
     * @param payloadDto 负载信息
     * @param secret     秘钥
     * @return 返回Token字符串
     * @throws JOSEException 生成异常
     */
    public String generateTokenByHmac(PayloadDTO payloadDto, String secret) throws JOSEException {
        //1 创建JWS头，设置签名算法和类型
        JWSHeader jwsHeader = new JWSHeader.Builder(JWSAlgorithm.HS256).type(JOSEObjectType.JWT).build();
        //2 将负载信息封装到Payload中
        Payload payload = new Payload(JSONUtil.toJsonStr(payloadDto));
        //3 创建JWS对象
        JWSObject jwsObject = new JWSObject(jwsHeader, payload);
        //4 创建HMAC签名器
        secret = SecureUtil.md5(secret);
        JWSSigner jwsSigner = new MACSigner(secret);
        //5 签名
        jwsObject.sign(jwsSigner);
        return jwsObject.serialize();
    }

    /**
     * 验证HMAC Token
     *
     * @param token  token字符串
     * @param secret 密钥
     * @return 负载信息对象
     * @throws Exception 验证异常
     */
    public PayloadDTO verifyTokenByHmac(String token, String secret) throws Exception {
        //1 从token中解析JWS对象
        JWSObject jwsObject = JWSObject.parse(token);
        //2 创建HMAC验证器
        secret = SecureUtil.md5(secret);
        JWSVerifier jwsVerifier = new MACVerifier(secret);
        //3 验证并获取负载信息
        return parseToPayloadDto(jwsObject, jwsVerifier);
    }

    /**
     * 通过RSA生成token
     * @param payloadDto 负载信息
     * @param rsaKey 签名Key
     * @return 返回Token字符串
     * @throws JOSEException 生成异常
     */
    public String generateTokenByRsa(PayloadDTO payloadDto, RSAKey rsaKey) throws JOSEException {
        //1 创建JWS头，设置签名算法和类型
        JWSHeader jwsHeader = new JWSHeader.Builder(JWSAlgorithm.RS256).type(JOSEObjectType.JWT).build();
        //2 将负载信息封装到Payload中
        Payload payload = new Payload(JSONUtil.toJsonStr(payloadDto));
        //3 创建JWS对象
        JWSObject jwsObject = new JWSObject(jwsHeader, payload);
        //4 创建RSA签名器
        JWSSigner jwsSigner = new RSASSASigner(rsaKey, true);
        //5 签名
        jwsObject.sign(jwsSigner);
        return jwsObject.serialize();
    }

    /**
     * 验证RSA Token
     * @param token token字符串
     * @param rsaKey 签名Key
     * @return 负载信息对象
     * @throws Exception 验证异常
     */
    public PayloadDTO verifyTokenByRsa(String token, RSAKey rsaKey) throws Exception {
        //1 从token中解析JWS对象
        JWSObject jwsObject = JWSObject.parse(token);
        RSAKey publicRsaKey = rsaKey.toPublicJWK();

        //2 使用RSA公钥创建RSA验证器
        JWSVerifier jwsVerifier = new RSASSAVerifier(publicRsaKey);

        //3 验证并获取负载信息
        return parseToPayloadDto(jwsObject, jwsVerifier);
    }

    @Value("classpath:public.pem")
    private Resource publicPem;

    @Value("classpath:private.pem")
    private Resource privatePem;

    /**
     * 通过默认公钥获取验证器
     *
     * @return 返回验证器
     */
    @Nullable
    private JWSVerifier getDefaultJwsVerifier() {
        try {
            // 读取公钥内容
            String publicKeyStr = StreamUtils.copyToString(publicPem.getInputStream(), Charset.defaultCharset());
            RSAKey rsaPublicKey = (RSAKey) JWK.parseFromPEMEncodedObjects(publicKeyStr);
            return new RSASSAVerifier(rsaPublicKey);
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    /**
     * 通过默认私钥获取签名器
     *
     * @return 签名器
     */
    @Nullable
    public JWSSigner getDefaultRsaJwsSigner() {
        try {
            // 读取私钥内容
            String privateKeyStr = StreamUtils.copyToString(privatePem.getInputStream(), Charset.defaultCharset());
            RSAKey rsaKey = (RSAKey) JWK.parseFromPEMEncodedObjects(privateKeyStr);
            return new RSASSASigner(rsaKey.toRSAPrivateKey());
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    /**
     * 默认RSA凭证验证
     *
     * @param token 验证凭证
     * @return 凭证的负载数据对应的字符串
     * @throws Exception 验证异常
     */
    @SuppressWarnings("MismatchedQueryAndUpdateOfCollection")
    public String defaultRsaVerify(String token) throws Exception {
        //1 解析Token
        JWSObject jwsObject = JWSObject.parse(token);
        //2 获取默认RSA验证器器
        JWSVerifier jwsVerifier = getDefaultJwsVerifier();
        if (jwsVerifier == null) {
            throw new JOSEException("签名验证器初始化失败");
        }
        //3 签名验证
        if (!jwsObject.verify(jwsVerifier)) {
            throw new JwtInvalidException("token签名不合法！");
        }
        //4 获取负载信息
        String payloadStr = jwsObject.getPayload().toString();
        JSONObject jsonObject = new JSONObject(payloadStr);
        //5 验证是否过期
        String expField = "exp";
        int mill = 1000;
        if (Convert.toLong(jsonObject.get(expField)) < System.currentTimeMillis() / mill) {
            throw new JwtExpiredException("token已过期！");
        }
        return payloadStr;
    }
}
