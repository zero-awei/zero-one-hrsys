package com.zeroone.star.common.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.common.entity.MaritalStatus;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;
@Mapper
public interface MaritalStatusMapper extends BaseMapper<MaritalStatus> {

    @Select("select marital_status_type as 'key',marital_status_code as 'value' from zo_marital_status;")
    List<DropdownListOptionDTO> selectMatrialStatus();


}
