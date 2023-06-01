package com.zeroone.star.common.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.common.entity.Pimperson;
import com.zeroone.star.project.dto.common.StatusListDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * 人员信息 Mapper 接口
 * </p>
 *
 * @author wxs
 * @since 2023-05-23
 */
@Mapper
public interface PimpersonMapper extends BaseMapper<Pimperson> {

    @Select("SELECT PERSONSTATEMGRNAME AS 'status', PERSONSTATEMGRID AS 'id' FROM t_personstatemgr;")
    List<StatusListDTO> selectEmployeeStatus();
}
