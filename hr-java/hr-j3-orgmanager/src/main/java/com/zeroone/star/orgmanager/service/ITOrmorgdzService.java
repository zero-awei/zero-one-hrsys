package com.zeroone.star.orgmanager.service;

import com.zeroone.star.orgmanager.entity.TOrmorgdz;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j3.dto.orgmager.OrgAddressDto;
import com.zeroone.star.project.j3.dto.orgmanager.ExportOrgAddressDto;
import com.zeroone.star.project.j3.dto.orgmanager.ModifyOrgAddressDTO;
import com.zeroone.star.project.j3.dto.orgmanager.OrgAddressDTO;
import com.zeroone.star.project.j3.query.OrgQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * <p>
 * 组织地址维护 服务类
 * </p>
 *
 * @author wh
 * @since 2023-05-31
 */
public interface ITOrmorgdzService extends IService<TOrmorgdz> {

	/**
	 * @Title: updateOrgAddress
	 * @Description: 修改组织地址信息（导入的地址也通过这个接口更新）
	 * @Author: wh
	 * @DateTime: 2023/6/1 16:37
	 * @param modifyOrgAddressDTOs
	 * @return int
	 */
	public int updateOrgAddress(List<ModifyOrgAddressDTO> modifyOrgAddressDTOs);

	boolean deleteOrgAddress(OrgAddressDto orgAddressDto);

	ExportOrgAddressDto exportOrgAddress(OrgAddressDto ids) throws Exception;

	/**
	 * @Title: listOrgAddress
	 * @Description: 分页查询指定组织地址列表
	 * @Author: wh
	 * @DateTime: 2023/6/9 20:49
	 * @param query
	 * @return com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.dto.PageDTO<com.zeroone.star.project.j3.dto.orgmanager.OrgAddressDTO>>
	 */
	JsonVO<PageDTO<OrgAddressDTO>> listOrgAddress(OrgQuery query);

}
