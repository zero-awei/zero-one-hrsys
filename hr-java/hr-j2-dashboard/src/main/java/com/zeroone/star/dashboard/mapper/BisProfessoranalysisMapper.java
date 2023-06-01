package com.zeroone.star.dashboard.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.dashboard.entity.BisProfessoranalysis;
import com.zeroone.star.project.dto.dashboard.PimTitleDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * 职称信息表 Mapper 接口
 * </p>
 *
 * @author wxs
 * @since 2023-05-23
 */
@Mapper
public interface BisProfessoranalysisMapper extends BaseMapper<BisProfessoranalysis> {

    @Select("SELECT COUNT(a.ORDERVALUE) AS 'count',a.TITLEGRADENAME AS 'zcdj' FROM bis_titlegrade_t a INNER JOIN bis_professoranalysis_t b on a.ORDERVALUE = b.PROFESSOR_GRADES GROUP BY a.TITLEGRADENAME;")
    List<PimTitleDTO> selectRank();

}
