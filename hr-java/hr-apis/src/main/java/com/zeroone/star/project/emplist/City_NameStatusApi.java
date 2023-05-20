package com.zeroone.star.project.emplist;


import com.zeroone.star.project.dto.city_namestatuslist.CityNameStatusListDTO;

import com.zeroone.star.project.query.city_namestatuslist.CityNameStatusListQuery;

import com.zeroone.star.project.vo.JsonVO;

public interface City_NameStatusApi {

    /**
     *
     * @param query
     * @return
     */
    JsonVO<CityNameStatusListDTO> queryAll(CityNameStatusListQuery query);
}
