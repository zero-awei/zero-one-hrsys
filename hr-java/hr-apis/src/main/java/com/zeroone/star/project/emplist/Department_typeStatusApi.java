package com.zeroone.star.project.emplist;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.department_typestatuslist.Department_typeStatusListDTO;
import com.zeroone.star.project.query.department_typestatuslist.Department_typeStatusListQuery;
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
    JsonVO<PageDTO<Department_typeStatusListDTO>> queryAll(Department_typeStatusListQuery query);
}
