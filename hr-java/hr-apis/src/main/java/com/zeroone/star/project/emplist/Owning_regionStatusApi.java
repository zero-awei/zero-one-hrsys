package com.zeroone.star.project.emplist;

/**
 * @author abner
 * @version 1.0
 */
import com.zeroone.star.project.dto.PageDTO;


import com.zeroone.star.project.dto.owning_regionstatuslist.OwningRegionStatusListDTO;
import com.zeroone.star.project.query.owning_regionstatuslist.OwningRegionStatusListQuery;
import com.zeroone.star.project.vo.JsonVO;

public interface Owning_regionStatusApi {
    /**
     *
     * @param query
     * @return
     */
    JsonVO<PageDTO<OwningRegionStatusListDTO>> queryAll(OwningRegionStatusListQuery query);

}
