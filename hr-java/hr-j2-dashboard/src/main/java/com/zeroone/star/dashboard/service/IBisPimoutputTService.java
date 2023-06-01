package com.zeroone.star.dashboard.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.dashboard.entity.BisPimoutputT;
import com.zeroone.star.project.dto.dashboard.PimOutputDTO;

import java.util.List;


/**
 * <p>
 *  服务类
 * </p>
 *
 * @author wxs
 * @since 2023-06-01
 */
public interface IBisPimoutputTService extends IService<BisPimoutputT> {
    /**
     * 月均产值
     * @return
     */
    List<PimOutputDTO> listMonthOutput();
}
