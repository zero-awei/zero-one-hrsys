package com.zeroone.star.project.j3.orgmanager;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sample.SampleDTO;
import com.zeroone.star.project.j3.dto.AddOrgInfoDTO;
import com.zeroone.star.project.j3.dto.DeleteDTO;
import com.zeroone.star.project.j3.dto.ExportDTO;
import com.zeroone.star.project.j3.dto.orgmanager.ExportOrgAddressDto;
import com.zeroone.star.project.j3.dto.orgmanager.ModifyOrgAddressDTO;
import com.zeroone.star.project.j3.dto.orgmanager.OrgAddressDto;
import com.zeroone.star.project.j3.dto.orgmanager.OrgInfoDTO;
import com.zeroone.star.project.j3.query.OrgQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * <p>
 * 描述：组织地址接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 梧桐
 * @version 1.0.0
 */
public interface OrgInfoApis {

    JsonVO<Boolean> deleteDepAddress(OrgAddressDto orgAddressDto);

    /**
     * 修改组织信息数据
     * @param orgInfoDTO 修改数据内容
     * @return 是否修改成功
     */
    JsonVO<Boolean> modifyOrgInfo(OrgInfoDTO orgInfoDTO);

    /**
     * @param modifyOrgAddressDTOs 需要更新的组织id和地址DTO集合
     * @return com.zeroone.star.project.vo.JsonVO<java.lang.Boolean>
     * @Title: modifyOrgAddress
     * @Description: 更新指定组织地址信息（导入的地址也通过这个接口更新）
     * @Author: wh
     * @DateTime: 2023/5/22 16:24
     */
    JsonVO<Boolean> modifyOrgAddress(List<ModifyOrgAddressDTO> modifyOrgAddressDTOs);

    /**
     * 批量删除组织信息
     * @param ids 组织唯一编号列表
     * @return 删除结果
     */
    JsonVO<Boolean> removeOrgData(DeleteDTO ids);

    /**
     * 删除组织地址接口
     * @param ids
     */
    JsonVO<Boolean> deleteOrgAddress(OrgAddressDto ids);

    /**
     * 导出组织地址接口
     * @param ids,ids
     */
    JsonVO<ExportOrgAddressDto> exportOrgAddress(OrgAddressDto ids) throws Exception;


    /**
     * 添加组织信息
     * @param addOrgInfoDTO 添加组织的内容
     * @return 是否添加成功信息
     */
    JsonVO<String> addOryData(AddOrgInfoDTO addOrgInfoDTO);

    /**
     * 分页查询指定组织地址列表
     * @param condition condition
     * @return {@link JsonVO< PageDTO< SampleDTO>>}
     * @Author H_lzu
     * @Date 17:16 2023/5/24
     */
    JsonVO<PageDTO<SampleDTO>> queryAllOrg(OrgQuery condition);

    /**
     * 导出组织（本页在前端完成）
     * @return {@link JsonVO< ExportDTO>}
     * @Author H_lzu
     * @Date 23:38 2023/5/30
     */
    JsonVO<ExportDTO> exportOrg() throws Exception;

    /**
     * 删除组织（支持批量删除）
     * @param orgIds
     * @return
     */
    JsonVO<Boolean> deleteOrg(List<String> orgIds);

}
