package com.zeroone.star.common.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.common.entity.WorkStatus;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

@Mapper
public interface WorkStatusMapper extends BaseMapper<WorkStatus> {

    @Select("select work_status_type as 'key',work_status_code as 'value' from zo_work_status;")
    List<DropdownListOptionDTO> selectWorkStatus();

}
