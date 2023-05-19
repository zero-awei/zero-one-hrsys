package com.zeroone.star.project.dashboard;

import com.zeroone.star.project.dto.dashboard.PimOutputDTO;
import com.zeroone.star.project.dto.dashboard.PimTitleDTO;
import com.zeroone.star.project.vo.JsonVO;

public interface DashBoardApi {

    /**
     * 职称等级查询
     * @return
     */
    JsonVO<PimTitleDTO> queryProfessionalRank();

    /**
     * 月均产值
     * @return
     */
    JsonVO<PimOutputDTO> queryByMonth();
}
