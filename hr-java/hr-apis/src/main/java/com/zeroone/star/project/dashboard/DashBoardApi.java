package com.zeroone.star.project.dashboard;

import com.zeroone.star.project.dto.dashboard.PimOutputDto;
import com.zeroone.star.project.dto.dashboard.PimTitleDto;
import com.zeroone.star.project.vo.JsonVO;

public interface DashBoardApi {

    /**
     * 职称等级查询
     * @return
     */
    JsonVO<PimTitleDto> queryProfessionalRank();

    /**
     * 月均产值
     * @return
     */
    JsonVO<PimOutputDto> queryByMonth();
}
