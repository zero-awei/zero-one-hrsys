package com.zeroone.star.dashboard.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.dashboard.entity.BisEducation;
import com.zeroone.star.project.query.dashboard.EducationQuery;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * 学历代码表 Mapper 接口
 * </p>
 *
 * @author rqs
 * @since 2023-05-18
 */
@Mapper
public interface BisEducationMapper extends BaseMapper<BisEducation> {

    /**
     * @Description: 查询学历分布
     * @params: []
     * @return: List<EducationQuery>
     * @Author: Rqs
     * @Date: 2023/5/22 23:53
     */
    @Select("select b.EDUCATIONNAME,count(*) as count from t_pimperson t inner join bis_education_t b on t.HIGHEDUCATION=b.EDUCATIONID group by  t.HIGHEDUCATION ")
    List<EducationQuery> selectEducationQueryList();
}
