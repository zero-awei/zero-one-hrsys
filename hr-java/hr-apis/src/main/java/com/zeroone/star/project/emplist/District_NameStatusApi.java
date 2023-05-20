package com.zeroone.star.project.emplist;

import com.zeroone.star.project.dto.district_namestatuslist.DistrictNamestatusListDTO;

import com.zeroone.star.project.query.district_namestatuslist.DistrictNameStatusListQuery;

import com.zeroone.star.project.vo.JsonVO;

public interface District_NameStatusApi {
    /**
     *
     * @param query
     * @return
     */
    JsonVO<DistrictNamestatusListDTO> queryAll(DistrictNameStatusListQuery query);
}
