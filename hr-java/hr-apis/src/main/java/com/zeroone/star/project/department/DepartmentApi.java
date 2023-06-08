package com.zeroone.star.project.department;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.orgmanager.DepartmentDTO;
import com.zeroone.star.project.query.orgmanager.DepartmentQuery;
import com.zeroone.star.project.vo.JsonVO;

public interface DepartmentApi {

    /**
     *分页查询部门信息
     * @param query
     * @return
     */
    JsonVO<PageDTO<DepartmentDTO>> queryAllDepartment(DepartmentQuery query);

}
