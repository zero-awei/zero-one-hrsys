package com.zeroone.star.project.emplist;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.statuslist.WorkStatusListDTO;
import com.zeroone.star.project.query.statuslist.WorkStatusListQuery;
import com.zeroone.star.project.vo.JsonVO;

public interface WorkStatusApi {

    JsonVO<PageDTO<WorkStatusListDTO>> queryAll(WorkStatusListQuery query);
}
