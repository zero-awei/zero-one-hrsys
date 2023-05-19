package com.zeroone.star.project.emplist;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.organizational_propertystatuslist.OrganizationalPropertyStatusListDTO;
import com.zeroone.star.project.query.organizational_propertystatuslist.OrganizationalPropertyStatusListQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * @author abner
 * @version 1.0
 */
public interface Organizational_propertyStatusApi {
    /**
     *
     * @param query
     * @return
     */
    JsonVO<PageDTO<OrganizationalPropertyStatusListDTO>> queryAll(OrganizationalPropertyStatusListQuery query);
}
