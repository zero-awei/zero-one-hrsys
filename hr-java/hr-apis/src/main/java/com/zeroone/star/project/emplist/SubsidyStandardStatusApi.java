package com.zeroone.star.project.emplist;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.subsidystandardstatuslist.SubsidyStandardStatusListDTO;
import com.zeroone.star.project.query.subsidystandardstatuslist.SubsidyStandardStatusListQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * @author abner
 * @version 1.0
 */
public interface SubsidyStandardStatusApi {
    /**
     *
     * @param query
     * @return
     */
    JsonVO<PageDTO<SubsidyStandardStatusListDTO>> queryAll(SubsidyStandardStatusListQuery query);
}
