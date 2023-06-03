package com.zeroone.star.common.service;

import com.zeroone.star.common.entity.TOrmpost;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.j3.dto.DropdownListOptionDTO;
import com.zeroone.star.project.j3.query.common.JobTitleDropdownListQuery;

import java.util.List;

/**
 * <p>
 * 岗位集 服务类
 * </p>
 *
 * @author wh
 * @since 2023-05-29
 */
public interface ITOrmpostService extends IService<TOrmpost> {

	/**
	 * @Title: listPosts
	 * @Description: 根据组织名称查询岗位信息
	 * @Author: wh
	 * @DateTime: 2023/5/29 18:19
	 * @param jobTitleDropdownListQuery
	 * @return java.util.List<com.zeroone.star.project.j3.dto.DropdownListOptionDTO>
	 */
	public List<DropdownListOptionDTO> listPosts(JobTitleDropdownListQuery jobTitleDropdownListQuery);
}
