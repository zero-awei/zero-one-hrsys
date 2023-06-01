package com.zeroone.star.dashboard.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.dashboard.entity.BisProfessoranalysis;
import com.zeroone.star.project.dto.dashboard.PimTitleDTO;

import java.util.List;

/**
 * <p>
 * 职称信息表 服务类
 * </p>
 *
 * @author wxs
 * @since 2023-05-23
 */
public interface IBisProfessoranalysisService extends IService<BisProfessoranalysis> {
    List<PimTitleDTO> listRank();
}
