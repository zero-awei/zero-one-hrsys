package com.zeroone.star.project.dashboard;

import com.zeroone.star.project.dto.dashboard.PimOutputDTO;
import com.zeroone.star.project.vo.JsonVO;

public interface PimOutputApi {

    /**
     * 月均产值查询
     * @return
     */
    JsonVO<PimOutputDTO> countByYear();
}
