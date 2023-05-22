package com.zeroone.star.project.j3.orgmanager;

import cn.hutool.http.server.HttpServerResponse;
import com.zeroone.star.project.j3.dto.orgmanager.ExportOrgAddressDto;
import com.zeroone.star.project.j3.dto.orgmanager.OrgAddressDto;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * <p>
 * 描述：组织地址接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 梧桐
 * @version 1.0.0
 */
public interface OrgInfoApis {

    /**
     * 删除组织地址接口
     * @param ids
     */
    JsonVO<Boolean> deleteOrgAddress(OrgAddressDto ids);

    /**
     * 导出组织地址接口
     * @param ids
     */
    JsonVO<List<ExportOrgAddressDto>> exportOrgAddress(OrgAddressDto ids);
}
