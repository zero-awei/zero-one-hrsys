package com.zeroone.star.project.emplist;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.statuslist.MaritalStatusListDTO;
import com.zeroone.star.project.query.statuslist.MaritalStatusListQuery;
import com.zeroone.star.project.vo.JsonVO;

public interface MaritalStatusApi {
    /**
     *
     * @param query
     * @return
     */
    JsonVO<PageDTO<MaritalStatusListDTO>> queryAll(MaritalStatusListQuery query);

}
