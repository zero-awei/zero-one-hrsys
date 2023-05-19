package com.zeroone.star.project.j3.orgmanager;

import com.zeroone.star.project.j3.dto.OrgAddressDto;
import com.zeroone.star.project.vo.JsonVO;

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
     * @param orgAddressDto
     * @return 删除行数
     */
    JsonVO<Integer> deleteDepAddress(OrgAddressDto orgAddressDto);
}
