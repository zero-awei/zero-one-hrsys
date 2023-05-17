package com.zeroone.star.project.oauth;

import com.zeroone.star.project.dto.login.Oauth2TokenDTO;
import com.zeroone.star.project.vo.JsonVO;

import java.security.Principal;
import java.util.Map;

/**
 * <p>
 * 描述：认证授权接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
public interface AuthApis {
    /**
     * 授权认证接口
     * @param principal  安全主体对象
     * @param parameters 传递参数
     * @return 响应结果
     */
    JsonVO<Oauth2TokenDTO> postAccessToken(Principal principal, Map<String, String> parameters);
}
