package com.zeroone.star.project.emplist;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.statuslist.MaritalStatusListDTO;
import com.zeroone.star.project.query.statuslist.MaritalStatusListQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

public interface MaritalStatusApi {
    /**
     *
     * @param query
     * @return
     */
    JsonVO<List<MaritalStatusListDTO>> queryAll(MaritalStatusListQuery query);

}
