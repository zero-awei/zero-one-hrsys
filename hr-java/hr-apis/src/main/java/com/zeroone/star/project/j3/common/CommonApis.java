package com.zeroone.star.project.j3.common;

import com.zeroone.star.project.j3.dto.DropdownListOptionDTO;
import com.zeroone.star.project.j3.query.common.OneConditionQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * <p>
 * 描述：公共接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 小吴
 * @version 1.0.0
 * @Date 2023/5/18 23:43
 */
public interface CommonApis {

	/**
	 * 获取分配信息中的职务信息数据接口
	 * @param oneConditionQuery 查询的字段名
	 * @return 查询结果
	 */
	JsonVO<List<String>> queryOneColumn(OneConditionQuery oneConditionQuery);
/**
 *
 * @return {@link JsonVO< List< DropdownListOptionDTO>>}
 * @Author H_lzu
 * @Date 20:27 2023/5/19
 */
	JsonVO<List<DropdownListOptionDTO>> queryRewardPenaltyLevels();
/**
 * 军转类型下拉列表
 * @return
 * @return {@link JsonVO< List< DropdownListOptionDTO>>}
 * @Author H_lzu
 * @Date 20:24 2023/5/19
 */
	JsonVO<List<DropdownListOptionDTO>> queryTypeofMilitaryTransfer();
/**
 *  分配形式下拉列表
 * @return {@link JsonVO< List< DropdownListOptionDTO>>}
 * @Author H_lzu
 * @Date 20:45 2023/5/19
 */
	JsonVO<List<DropdownListOptionDTO>> queryDistributionForm();
	/**
	 *  分配状态下拉列表
	 * @return {@link JsonVO< List< DropdownListOptionDTO>>}
	 * @Author H_lzu
	 * @Date 20:47 2023/5/19
	 */
	JsonVO<List<DropdownListOptionDTO>> queryDistributionStatus();
/**
 *  组织形式下拉列表
 * @return {@link JsonVO< List< DropdownListOptionDTO>>}
 * @Author H_lzu
 * @Date 20:49 2023/5/19
 */
	JsonVO<List<DropdownListOptionDTO>> queryNameofAssociation();
/**
 *  部门名称下拉列表
 * @return {@link JsonVO< List< DropdownListOptionDTO>>}
 * @Author H_lzu
 * @Date 20:49 2023/5/19
 */
	JsonVO<List<DropdownListOptionDTO>> queryDepartmentName();
}

