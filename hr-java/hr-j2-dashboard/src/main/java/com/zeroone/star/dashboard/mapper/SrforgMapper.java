package com.zeroone.star.dashboard.mapper;

import com.zeroone.star.dashboard.entity.Srforg;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.dashboard.AgencyProjectStaffDTO;
import com.zeroone.star.project.dto.dashboard.OrgDistributeDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * Mapper 接口
 * </p>
 *
 * @author letian
 * @since 2023-05-21
 */
@Mapper
public interface SrforgMapper extends BaseMapper<Srforg> {
    /**
     * @param :
     * @return List<OrgDistributeDTO>
     * @author 乐天
     * @description:从t_srforg表和t_pimperson查询组织信息和对应的组织人数
     * @date 2023/5/22 8:13
     */
    @Select("select b.ORGNAME as 'orgName', count(a.ORMORGNAME) as 'number' " +
            "from t_pimperson a " +
            "inner join t_srforg b " +
            "on a.ORMORGID = b.ORGID " +
            "group by b.ORGID;")
    List<OrgDistributeDTO> selectOrgDistribute();

    @Select("SELECT ormtype, count(1) AS countnum FROM BIS_EMPLOYEEANALYSIS_T GROUP BY ormtype")
    List<AgencyProjectStaffDTO> selectAgencyProjectStaff();


}
