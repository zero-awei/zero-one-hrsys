package com.zeroone.star.dashboard.mapper;

import com.zeroone.star.dashboard.entity.BisEmployeeanalysis;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.dashboard.AgencyProjectStaffDTO;
import com.zeroone.star.project.dto.dashboard.OrgEmployeeCountDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * 员工基本信息分析表 Mapper 接口
 * </p>
 *
 * @author letian
 * @since 2023-05-21
 */
@Mapper
public interface BisEmployeeanalysisMapper extends BaseMapper<BisEmployeeanalysis> {
    /**
     * @param :
     * @return List<OrgEmployeeCountDTO>
     * @author 乐天
     * @description：从bis_employeeanalysis_t表中查询每个组织所对应的人数
     * @date 2023/5/22 8:14
     */
    @Select("select count(a.EMPLOYEENAME) from bis_employeeanalysis_t a " +
            "inner join t_srforg b on a.ORGANIZATION_ID = b.ORGID group by b.ORGID;")
    List<OrgEmployeeCountDTO> selectOrgEmployeeCount();

    @Select("SELECT ormtype, count(1) AS countnum FROM BIS_EMPLOYEEANALYSIS_T GROUP BY ormtype")
    List<AgencyProjectStaffDTO> selectAgencyProjectStaff();
}
