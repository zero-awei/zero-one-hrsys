package com.zeroone.star.dashboard.mapper;

import com.zeroone.star.dashboard.entity.Srforg;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.dashboard.OrgDistributeDTO;
import com.zeroone.star.project.dto.dashboard.OrgEmployeeCountDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * 组织机构 Mapper 接口
 * </p>
 *
 * @author letian
 * @since 2023-05-21
 */
@Mapper
public interface SrforgMapper extends BaseMapper<Srforg> {
    @Select("select ORGNAME from t_srforg;")
    List<OrgDistributeDTO> selectAllOrg();

    @Select("select count(a.EMPLOYEENAME) from bis_employeeanalysis_t a " +
            "inner join t_srforg b on a.ORGANIZATION_ID = b.ORGID group by b.ORGID;")
    List<OrgEmployeeCountDTO> selectOrgEmployeeCount();
}
