package com.zeroone.star.dashboard.service;

import com.zeroone.star.dashboard.entity.Pimoutput;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.dashboard.PimOutputDTO;

import java.util.List;

/**
 * <p>
 * 产值表 服务类
 * </p>
 *
 * @author wxs
 * @since 2023-05-23
 */
public interface IPimoutputService extends IService<Pimoutput> {
    List<PimOutputDTO> listYd();
}
