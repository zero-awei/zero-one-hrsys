package com.zeroone.star.common.mapper;


import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.common.entity.TPimlanguageability;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * 语言能力 Mapper 接口
 * </p>
 *
 * @author loop
 * @since 2023-05-29
 */
@Mapper
public interface TPimlanguageabilityMapper extends BaseMapper<TPimlanguageability> {

    /**
     * 获取下拉列表项
     * @param id
     * @return
     */
    @Select("select CODEITEMNAME from t_srfcodeitem where CODELISTID = #{id}")
    public List<String> queryLanguageLevel(String id);

    @Select("select CODEITEMNAME from t_srfcodeitem where CODELISTID = #{id}")
    public List<String> queryLanguageType(String id);

    @Select("select CODEITEMNAME from t_srfcodeitem where CODELISTID = #{id}")
    public List<String> queryRelationship(String id);
}
