package com.zeroone.star.dashboard.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.dashboard.entity.BisRegisterT;
import com.zeroone.star.project.dto.dashboard.PimVocationalDTO;

import java.util.List;

/**
 * <p>
 * 执业职格信息表 服务类
 * </p>
 *
 * @author mwx
 * @since 2023-05-24
 */

public interface IBisRegisterTService extends IService<BisRegisterT> {
    List<PimVocationalDTO> listVocational();
}
