package com.zeroone.star.common.mapper;

import com.zeroone.star.common.entity.Pimperson;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.common.GwTypeDTO;
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

    @Select("select a.PIMPERSONID,b.PERSONSTATEMGRNAME FROM t_pimperson a INNER JOIN t_personstatemgr b;")
    List<StatusListDTO> selectEmployeeStatus();
}
