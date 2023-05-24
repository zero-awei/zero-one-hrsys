package com.zeroone.star.common.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.common.entity.ZoMaritalStatus;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;

import java.util.List;

public interface IZoMaritalStatusService extends IService<ZoMaritalStatus> {

    /**
     * 查询婚姻状态下拉列表
     * @return
     */
    List<DropdownListOptionDTO> listMaritalStatus();

}
