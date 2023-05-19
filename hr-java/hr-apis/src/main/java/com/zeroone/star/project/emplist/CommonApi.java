package com.zeroone.star.project.emplist;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.common.StatusListDTO;
import com.zeroone.star.project.query.departmenttypestatuslist.DepartmentTypeStatusListQuery;
import com.zeroone.star.project.vo.JsonVO;

public interface CommonApi {

    /**
     * 查询员工状态信息
     * @return
     */
    JsonVO<PageDTO<StatusListDTO>> queryEmployeeStatus();

}


