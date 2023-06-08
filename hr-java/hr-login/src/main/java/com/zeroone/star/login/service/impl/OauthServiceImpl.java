package com.zeroone.star.login.service.impl;

import com.zeroone.star.login.service.OauthService;
import com.zeroone.star.project.dto.login.Oauth2TokenDTO;
import com.zeroone.star.project.vo.JsonVO;
import lombok.AllArgsConstructor;

import java.util.Map;

/**
 * <p>
 * 描述：授权服务降级实现
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@AllArgsConstructor
public class OauthServiceImpl implements OauthService {
    private Throwable throwable;

    private void setMessage(JsonVO<?> vo) {
        if (throwable.getMessage() != null) {
            vo.setMessage(throwable.getMessage());
        } else {
            vo.setMessage(throwable.getClass().toGenericString());
        }
    }

    @Override
    public JsonVO<Oauth2TokenDTO> postAccessToken(Map<String, String> parameters) {
        JsonVO<Oauth2TokenDTO> vo = JsonVO.fail(null);
        setMessage(vo);
        return vo;
    }
}
