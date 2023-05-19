package com.zeroone.star.project.emplist;

import com.zeroone.star.project.dto.district_namestatuslist.District_namestatusListDTO;
import com.zeroone.star.project.query.district_namestatuslist.District_NameStatusListQuery;
import com.zeroone.star.project.vo.JsonVO;

public interface District_NameStatusApi {
    /**
     *
     * @param query
     * @return
     */
    JsonVO<District_namestatusListDTO> queryAll(District_NameStatusListQuery query);
}
