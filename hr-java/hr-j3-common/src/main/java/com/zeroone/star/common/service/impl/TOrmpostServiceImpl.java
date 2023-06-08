package com.zeroone.star.common.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.common.entity.TOrmduty;
import com.zeroone.star.common.entity.TOrmpost;
import com.zeroone.star.common.mapper.TOrmpostMapper;
import com.zeroone.star.common.service.ITOrmpostService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.j3.dto.DropdownListOptionDTO;
import com.zeroone.star.project.j3.query.common.JobTitleDropdownListQuery;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 岗位集 服务实现类
 * </p>
 *
 * @author wh
 * @since 2023-05-29
 */
@Service
public class TOrmpostServiceImpl extends ServiceImpl<TOrmpostMapper, TOrmpost> implements ITOrmpostService {

	@Autowired
	TOrmpostMapper mapper;

	/**
	 * @Title: listPosts
	 * @Description: 根据组织名称查找相应的岗位名称
	 * @Author: wh
	 * @DateTime: 2023/5/29 23:45
	 * @param jobTitleDropdownListQuery
	 * @return java.util.List<java.lang.String>
	 */
	@Override
	public List<DropdownListOptionDTO> listPosts(JobTitleDropdownListQuery jobTitleDropdownListQuery) {
		//组织名称
		String orgName = jobTitleDropdownListQuery.getOrmorinfoname();
		//查询数据
		List<TOrmpost> list = mapper.selectOrmpostByOrgName(orgName);
		//创建储存结果的list
		ArrayList<DropdownListOptionDTO> postList = new ArrayList<>();

		for (TOrmpost tOrmpost : list) {
			DropdownListOptionDTO dto = new DropdownListOptionDTO();
			dto.setValue(tOrmpost.getOrmpostname());
			postList.add(dto);
		}
		return postList;
	}

}
