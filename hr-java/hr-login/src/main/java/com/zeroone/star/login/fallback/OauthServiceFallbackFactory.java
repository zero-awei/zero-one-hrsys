package com.zeroone.star.login.fallback;

import com.zeroone.star.login.service.impl.OauthServiceImpl;
import feign.hystrix.FallbackFactory;
import org.springframework.stereotype.Component;

/**
 * <p>
 * 描述：授权服务异常回调工厂
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Component
public class OauthServiceFallbackFactory implements FallbackFactory<OauthServiceImpl> {
    @Override
    public OauthServiceImpl create(Throwable throwable) {
        return new OauthServiceImpl(throwable);
    }
}
