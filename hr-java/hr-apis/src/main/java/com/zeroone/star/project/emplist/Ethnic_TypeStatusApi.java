package com.zeroone.star.project.emplist;

import com.zeroone.star.project.dto.ethnic_typestatuslist.Ethnic_typestatusListDTO;
import com.zeroone.star.project.query.ethnic_typestatuslist.Ethnic_TypeStatusListQuery;
import com.zeroone.star.project.vo.JsonVO;

public interface Ethnic_TypeStatusApi {


    /**
     *
     * @param query
     * @return
     */
    JsonVO<Ethnic_typestatusListDTO> queryall(Ethnic_TypeStatusListQuery query);
}
