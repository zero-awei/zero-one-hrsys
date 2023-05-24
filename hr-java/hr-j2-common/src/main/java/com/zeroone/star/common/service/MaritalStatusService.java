package com.zeroone.star.common.service;

import com.zeroone.star.project.dto.common.DropdownListOptionDTO;

import java.util.List;

public interface MaritalStatusService {

    /**
     * 查询婚姻状态下拉列表
     * @return
     */
    List<DropdownListOptionDTO> listMaritalStatus();

}
