package com.zeroone.star.dashboard.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.dashboard.entity.BisPimoutputT;
import com.zeroone.star.project.dto.dashboard.PimOutputDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;


/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author wxs
 * @since 2023-06-01
 */
@Mapper
public interface BisPimoutputTMapper extends BaseMapper<BisPimoutputT> {


    @Select("SELECT AVG(OUTPUT) AS OUTPUT,MONTHLY FROM bis_pimoutput_t GROUP BY MONTHLY ORDER BY OUTPUT;")
    List<PimOutputDTO> selectMonthOutput();
}
