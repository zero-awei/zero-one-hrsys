package com.zeroone.star.project.emplist;


import com.zeroone.star.project.dto.city_namestatuslist.City_NameStatusListDTO;
import com.zeroone.star.project.query.city_namestatuslist.City_NameStatusListQuery;
import com.zeroone.star.project.vo.JsonVO;

public interface City_NameStatusApi {

    /**
     *
     * @param query
     * @return
     */
    JsonVO<City_NameStatusListDTO> queryAll(City_NameStatusListQuery query);
}
