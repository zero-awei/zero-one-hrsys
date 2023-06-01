package com.zeroone.star.common.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.common.entity.Zzmm;
import com.zeroone.star.project.dto.common.ZzmmDTO;
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

    @Select("SELECT t.ID,t.NAME FROM zo_pimzzmm t")
    List<ZzmmDTO> selectZzmmList();
}
