package com.zeroone.star.dashboard.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.dashboard.entity.BisEmployeeanalysis;
import com.zeroone.star.project.dto.dashboard.AgencyProjectStaffDTO;
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

    @Select("SELECT ormtype, count(1) AS countnum FROM BIS_EMPLOYEEANALYSIS_T GROUP BY ormtype")
    List<AgencyProjectStaffDTO> selectAgencyProjectStaff();
}
