package com.zeroone.star.project.emplist;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.subsidy_standardstatuslist.SubsidyStandardStatusListDTO;
import com.zeroone.star.project.query.subsidy_standardstatuslist.SubsidyStandardStatusListQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * @author abner
 * @version 1.0
 */
public interface Subsidy_standardStatusApi {
    /**
     *
     * @param query
     * @return
     */
    JsonVO<PageDTO<SubsidyStandardStatusListDTO>> queryAll(SubsidyStandardStatusListQuery query);
}
