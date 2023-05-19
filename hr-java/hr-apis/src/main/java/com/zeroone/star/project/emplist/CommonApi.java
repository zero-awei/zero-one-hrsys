package com.zeroone.star.project.emplist;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.common.StatusListDto;
import com.zeroone.star.project.vo.JsonVO;

public interface CommonApi {

    /**
     * 查询员工状态信息
     * @return
     */
    JsonVO<PageDTO<StatusListDto>> queryEmployeeStatus();
}
