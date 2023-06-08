package com.zeroone.star.dashboard.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.dashboard.entity.BisRegisterT;
import com.zeroone.star.project.dto.dashboard.PimVocationalDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * 执业职格信息表 Mapper 接口
 * </p>
 *
 * @author mwx
 * @since 2023-05-24
 */
@Mapper
public interface BisRegisterTMapper extends BaseMapper<BisRegisterT> {

    @Select("SELECT " +
            "CREDENTIALS_NAME AS 'qualificationName', " +
            "COUNT( CREDENTIALS_NAME ) AS 'countNum' " +
            "FROM " +
            "`bis_register_t` " +
            "GROUP BY " +
            "CREDENTIALS_NAME")
    List<PimVocationalDTO> selectVocational();

}
