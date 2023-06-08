package com.zeroone.star.common.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.common.entity.TPimcity;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import com.zeroone.star.project.query.common.DistrictNameQuery;

import java.util.List;

/**
 * <p>
 * 市 服务类
 * </p>
 *
 * @author 浅墨
 * @since 2023-06-04
 */
public interface ITPimcityService extends IService<TPimcity> {

    List<DropdownListOptionDTO> listDistrictName(DistrictNameQuery query);
}
