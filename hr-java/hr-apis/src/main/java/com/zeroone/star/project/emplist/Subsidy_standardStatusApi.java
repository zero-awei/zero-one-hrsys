package com.zeroone.star.project.emplist;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.subsidy_standardstatuslist.Subsidy_standardStatusListDTO;
import com.zeroone.star.project.query.subsidy_standardstatuslist.Subsidy_standardStatusListQuery;
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
    JsonVO<PageDTO<Subsidy_standardStatusListDTO>> queryAll(Subsidy_standardStatusListQuery query);
}
