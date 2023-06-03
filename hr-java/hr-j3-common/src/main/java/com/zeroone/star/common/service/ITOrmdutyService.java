package com.zeroone.star.common.service;

import com.zeroone.star.common.entity.TOrmduty;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.j3.dto.DropdownListOptionDTO;

import java.util.List;

/**
 * <p>
 * 职务管理 服务类
 * </p>
 *
 * @author wh
 * @since 2023-05-29
 */
public interface ITOrmdutyService extends IService<TOrmduty> {

	/**
	 * @Title: ListDuty
	 * @Description: 查询职务名称
	 * @Author: wh
	 * @DateTime: 2023/5/30 0:23
	 * @param
	 * @return java.util.List<com.zeroone.star.project.j3.dto.DropdownListOptionDTO>
	 */
	public List<DropdownListOptionDTO> ListDuty();

}
