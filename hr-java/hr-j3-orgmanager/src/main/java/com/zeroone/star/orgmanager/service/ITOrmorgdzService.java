package com.zeroone.star.orgmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.orgmanager.entity.TOrmorgdz;
import com.zeroone.star.project.j3.dto.orgmanager.ExportOrgAddressDto;
import com.zeroone.star.project.j3.dto.orgmanager.ModifyOrgAddressDTO;
import com.zeroone.star.project.j3.dto.orgmanager.OrgAddressDto;

import java.util.List;

/**
 * <p>
 * 组织地址维护 服务类
 * </p>
 * @author wh
 * @since 2023-05-31
 */
public interface ITOrmorgdzService extends IService<TOrmorgdz> {

    /**
     * @param modifyOrgAddressDTOs
     * @return int
     * @Title: updateOrgAddress
     * @Description: 修改组织地址信息（导入的地址也通过这个接口更新）
     * @Author: wh
     * @DateTime: 2023/6/1 16:37
     */
    public int updateOrgAddress(List<ModifyOrgAddressDTO> modifyOrgAddressDTOs);

    boolean deleteOrgAddress(OrgAddressDto orgAddressDto);

    ExportOrgAddressDto exportOrgAddress(OrgAddressDto ids) throws Exception;

}
