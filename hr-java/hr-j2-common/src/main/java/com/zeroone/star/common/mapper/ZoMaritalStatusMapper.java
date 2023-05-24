package com.zeroone.star.common.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.common.entity.ZoMaritalStatus;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;
@Mapper
public interface ZoMaritalStatusMapper extends BaseMapper<ZoMaritalStatus> {

    @Select("select marital_status_code as 'key',marital_status_type as 'value' from zo_marital_status;")
    List<DropdownListOptionDTO> selectMatrialStatus();


}
