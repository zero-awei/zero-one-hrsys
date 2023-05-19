package com.zeroone.star.project.j3.orgmanager;

import com.zeroone.star.project.j3.dto.DepAddressDto;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 * 描述：部门地址接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 梧桐
 * @version 1.0.0
 */
public interface DepAddressApis {
    /**
     * 删除部门地址接口
     * @param depAddressDto
     * @return 删除行数
     */
    JsonVO<Integer> deleteDepAddress(DepAddressDto depAddressDto);
}
