package com.zeroone.star.project.emplist;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.statuslist.StatusListDto;
import com.zeroone.star.project.query.statuslist.StatusListQuery;
import com.zeroone.star.project.vo.JsonVO;

public interface StatusApi {

    JsonVO<PageDTO<StatusListDto>> queryAllStatus(StatusListQuery query);
}
