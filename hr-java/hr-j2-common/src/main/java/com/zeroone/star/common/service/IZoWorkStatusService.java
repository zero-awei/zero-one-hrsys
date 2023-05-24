package com.zeroone.star.common.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.common.entity.ZoWorkStatus;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;

import java.util.List;

/**
 * @author mwx
 * @version 1.0
 * @description: TODO
 * @date 2023/5/23 23:20
 */
public interface IZoWorkStatusService extends IService<ZoWorkStatus> {
    /**
     * 查询工作状态下拉列表
     * @return
     */
    List<DropdownListOptionDTO> listWorkStatus();
}
