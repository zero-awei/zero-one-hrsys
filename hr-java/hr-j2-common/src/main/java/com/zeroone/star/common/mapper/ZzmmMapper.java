package com.zeroone.star.common.mapper;

import com.zeroone.star.common.entity.Zzmm;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.common.ZzmmDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * 人员信息 Mapper 接口
 * </p>
 *
 * @author rqs
 * @since 2023-05-17
 */
@Mapper
public interface ZzmmMapper extends BaseMapper<Zzmm> {

    @Select("select * from t_pimzzmm")
    List<ZzmmDTO> selectZzmmList();
}
