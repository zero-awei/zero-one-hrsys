package com.zeroone.star.project.emplist;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.organizational_propertystatuslist.Organizational_propertyStatusListDTO;
import com.zeroone.star.project.query.organizational_propertystatuslist.Organizational_propertyStatusListQuery;
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
    JsonVO<PageDTO<Organizational_propertyStatusListDTO>> queryAll(Organizational_propertyStatusListQuery query);
}
