package com.zeroone.star.common.service;

import com.zeroone.star.project.dto.common.DropdownListOptionDTO;

import java.util.List;

public interface CommonService {
    List<DropdownListOptionDTO> listDropdownList(String name);
}
