package com.zeroone.star.dashboard.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.dashboard.entity.TPimperson;
import com.zeroone.star.project.dto.dashboard.AgeDTO;
import com.zeroone.star.project.dto.dashboard.OrgPersonCountDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * 人员信息 Mapper 接口
 * </p>
 *
 * @author letian
 * @since 2023-06-02
 */
@Mapper
public interface TPimpersonMapper extends BaseMapper<TPimperson> {
    @Select("select a.ORMORGID as 'ormOrgId', count(a.ORMORGNAME) as 'personCount' " +
            "from t_pimperson a " +
            "inner join t_srforg b " +
            "on a.ORMORGID = b.ORGID " +
            "group by b.ORGID;")
    List<OrgPersonCountDTO> selectOrgPersonCount();

    @Select("SELECT agetype AS agerange, count(1) AS agenum FROM (SELECT CASE WHEN age <= 30 THEN '30以下' WHEN age >= 31 AND age <= 35 THEN '31-35' WHEN age >= 36 AND age <= 40 THEN '36-40' WHEN age >= 41 AND age <= 45 THEN '41-45' WHEN age >= 46 AND age <= 50 THEN '46-50' WHEN age >= 51 AND age <= 55 THEN '51-55' ELSE '55以上' END agetype FROM (SELECT timestampdiff(YEAR, t1.CSRQ, sysdate()) AS age FROM t_pimperson t1 WHERE YGZT NOT IN ('40', '50', '60', '130', '51') AND jlss = '10' AND ENABLE = 1) x) y GROUP BY agetype ORDER BY agetype")
    List<AgeDTO> selectAgeDistribution();
}
