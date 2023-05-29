package com.zeroone.star.dashboard.mapper;

import com.zeroone.star.dashboard.entity.Pimoutput;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.dashboard.PimOutputDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * 产值表 Mapper 接口
 * </p>
 *
 * @author wxs
 * @since 2023-05-23
 */
@Mapper
public interface PimoutputMapper extends BaseMapper<Pimoutput> {

    @Select("select YD as 'yd' from t_pimoutput")
    public List<PimOutputDTO> selectYd();

}
