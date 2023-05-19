package com.zeroone.star.project.emplist;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.department_typestatuslist.DepartmentTypeStatusListDTO;
import com.zeroone.star.project.query.department_typestatuslist.DepartmentTypeStatusListQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * @author abner
 * @version 1.0
 */
public interface Department_typeStatusApi {
    /**
     *
     * @param query
     * @return
     */
    JsonVO<PageDTO<DepartmentTypeStatusListDTO>> queryAll(DepartmentTypeStatusListQuery query);
}
