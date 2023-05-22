package com.zeroone.star.project.emplist;

import com.zeroone.star.project.dto.ethnic_typestatuslist.EthnicTypestatusListDTO;

import com.zeroone.star.project.query.ethnic_typestatuslist.EthnicTypeStatusListQuery;

import com.zeroone.star.project.vo.JsonVO;

public interface EthnicTypeStatusApi {


    /**
     *
     * @param query
     * @return
     */
    JsonVO<EthnicTypestatusListDTO> queryall(EthnicTypeStatusListQuery query);
}
