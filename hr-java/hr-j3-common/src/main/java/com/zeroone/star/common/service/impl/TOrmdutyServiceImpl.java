package com.zeroone.star.common.service.impl;

import com.zeroone.star.common.entity.TOrmduty;
import com.zeroone.star.common.mapper.TOrmdutyMapper;
import com.zeroone.star.common.service.ITOrmdutyService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.j3.dto.DropdownListOptionDTO;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 职务管理 服务实现类
 * </p>
 *
 * @author wh
 * @since 2023-05-29
 */
@Service
public class TOrmdutyServiceImpl extends ServiceImpl<TOrmdutyMapper, TOrmduty> implements ITOrmdutyService {

	/**
	 * @Title: ListDuty
	 * @Description: 查询职务名称
	 * @Author: wh
	 * @DateTime: 2023/5/30 0:18
	 * @param
	 * @return java.util.List<com.zeroone.star.project.j3.dto.DropdownListOptionDTO>
	 */
	@Override
	public List<DropdownListOptionDTO> ListDuty() {
		//查询数据
		List<TOrmduty> tOrmduties = baseMapper.selectList(null);

		//创建list接收数据
		ArrayList<DropdownListOptionDTO> list = new ArrayList<>();

		for (TOrmduty tOrmduty : tOrmduties) {
			DropdownListOptionDTO dto = new DropdownListOptionDTO();
			dto.setValue(tOrmduty.getOrmdutyname());
			list.add(dto);
		}
		return list;
	}
}
