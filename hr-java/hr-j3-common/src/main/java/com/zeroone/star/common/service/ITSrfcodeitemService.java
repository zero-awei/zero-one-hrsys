package com.zeroone.star.common.service;

import com.zeroone.star.common.entity.TSrfcodeitem;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.j3.dto.DropdownListOptionDTO;

import java.util.List;

/**
 * <p>
 * 代码项 服务类
 * </p>
 *
 * @author H
 * @since 2023-05-28
 */
public interface ITSrfcodeitemService extends IService<TSrfcodeitem> {

    List<DropdownListOptionDTO> listDistributionStatus();
}
