package com.zeroone.star.project.dashboard;

import com.zeroone.star.project.dto.dashboard.PimTitleDto;
import com.zeroone.star.project.vo.JsonVO;

public interface PimTitleApi {

    /**
     * 职称等级查询
     * @return
     */
    JsonVO<PimTitleDto> query();
}
