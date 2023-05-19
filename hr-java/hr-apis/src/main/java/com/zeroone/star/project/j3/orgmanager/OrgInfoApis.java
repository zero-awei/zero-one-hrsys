package com.zeroone.star.project.j3.orgmanager;

import com.zeroone.star.project.j3.dto.orgmanager.OrgInfoDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 * 描述：组织信息模块接口定义
 * </p>
 * <p>版权：&copy;2023</p>
 * <p>地址：</p>
 *
 * @author 小吴
 * @version 1.0.0
 * @Date 2023/5/18 23:43
 */
public interface OrgInfoApis {

	/**
	 * 修改组织信息数据
	 * @param orgInfoDTO 修改数据内容
	 * @return 修改成功影响行数
	 */
	JsonVO<Long> modifyOrgInf(OrgInfoDTO orgInfoDTO);
}
