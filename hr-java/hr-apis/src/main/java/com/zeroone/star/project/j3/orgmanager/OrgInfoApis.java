package com.zeroone.star.project.j3.orgmanager;

import com.zeroone.star.project.j3.dto.DeleteDTO;
import com.zeroone.star.project.j3.dto.orgmanager.OrgInfoDTO;
import cn.hutool.http.server.HttpServerResponse;
import com.zeroone.star.project.j3.dto.orgmager.OrgAddressDto;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;

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

	JsonVO<Boolean> deleteDepAddress(OrgAddressDto orgAddressDto);

	/**
	  * 修改组织信息数据
	  *
	  * @param orgInfoDTO 修改数据内容
	  * @return 是否修改成功
	  */
	 JsonVO<Boolean> modifyOrgInfo(OrgInfoDTO orgInfoDTO);

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
    JsonVO<Boolean> exportOrgAddress(OrgAddressDto ids);



	/**
	 * 添加组织信息
	 * @param orgInfoDTO 添加组织的内容
	 * @return 是否添加成功
	 */
	JsonVO<Boolean> addOryData(OrgInfoDTO orgInfoDTO);

}
