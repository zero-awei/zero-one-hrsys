package com.zeroone.star.dashboard.mapper;

import com.zeroone.star.dashboard.entity.TPimperson;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.dashboard.OrgDistributeDTO;
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
}
