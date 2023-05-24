package com.zeroone.star.common.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.common.entity.ZoWorkStatus;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

@Mapper
public interface ZoWorkStatusMapper extends BaseMapper<ZoWorkStatus> {

    @Select("select work_status_code as 'key', work_status_type as 'value' from zo_work_status;")
    List<DropdownListOptionDTO> selectWorkStatus();

}
