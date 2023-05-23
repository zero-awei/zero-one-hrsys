package com.zeroone.star.project.emplist;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.statuslist.WorkStatusListDTO;
import com.zeroone.star.project.query.statuslist.WorkStatusListQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

public interface WorkStatusApi {

    JsonVO<List<WorkStatusListDTO>> queryAll(WorkStatusListQuery query);
}
