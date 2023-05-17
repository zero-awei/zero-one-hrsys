package com.zeroone.star.project.department;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.department.DepartmentDto;
import com.zeroone.star.project.query.department.DepartmentQuery;
import com.zeroone.star.project.vo.JsonVO;

public interface DepartmentApi {

    /**
     *
     * @param query
     * @return
     */
    JsonVO<PageDTO<DepartmentDto>> queryAll(DepartmentQuery query);

}
