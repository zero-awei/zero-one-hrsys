package com.zeroone.star.project.emplist;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.organizationalpropertystatuslist.OrganizationalPropertyStatusListDTO;
import com.zeroone.star.project.query.organizationalpropertystatuslist.OrganizationalPropertyStatusListQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * @author abner
 * @version 1.0
 */
public interface OrganizationalPropertyStatusApi {
    /**
     *
     * @param query
     * @return
     */
    JsonVO<PageDTO<OrganizationalPropertyStatusListDTO>> queryAll(OrganizationalPropertyStatusListQuery query);
}
