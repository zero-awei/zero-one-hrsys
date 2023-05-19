package com.zeroone.star.project.dashboard;

import com.zeroone.star.project.dto.dashboard.PimOutputDto;
import com.zeroone.star.project.vo.JsonVO;

public interface PimOutputApi {

    /**
     * 月均产值查询
     * @return
     */
    JsonVO<PimOutputDto> countByYear();
}
