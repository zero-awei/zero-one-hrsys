package com.zeroone.star.project.emplist;

/**
 * @author abner
 * @version 1.0
 */
import com.zeroone.star.project.dto.PageDTO;


import com.zeroone.star.project.dto.owningregionstatuslist.OwningRegionStatusListDTO;
import com.zeroone.star.project.query.owningregionstatuslist.OwningRegionStatusListQuery;
import com.zeroone.star.project.vo.JsonVO;

public interface OwningRegionStatusApi {
    /**
     *
     * @param query
     * @return
     */
    JsonVO<PageDTO<OwningRegionStatusListDTO>> queryAll(OwningRegionStatusListQuery query);

}
