package com.zeroone.star.project.emplist;

/**
 * @author abner
 * @version 1.0
 */
import com.zeroone.star.project.dto.PageDTO;


import com.zeroone.star.project.dto.owning_regionstatuslist.Owning_regionStatusListDTO;
import com.zeroone.star.project.query.owning_regionstatuslist.Owning_regionStatusListQuery;
import com.zeroone.star.project.vo.JsonVO;

public interface Owning_regionStatusApi {
    /**
     *
     * @param query
     * @return
     */
    JsonVO<PageDTO<Owning_regionStatusListDTO>> queryAll(Owning_regionStatusListQuery query);

}
