package com.zeroone.star.project.j3.orgmanager;

import com.zeroone.star.project.j3.dto.DeleteDTO;
import com.zeroone.star.project.j3.dto.orgmanager.OrgInfoDTO;
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
	 * 添加组织信息
	 * @param orgInfoDTO 添加组织的内容
	 * @return 是否添加成功
	 */
	JsonVO<Boolean> addOryData(OrgInfoDTO orgInfoDTO);

}
