package com.zeroone.star.project.dashboard;

import com.zeroone.star.project.dto.dashboard.AgencyProjectStaffDTO;
import com.zeroone.star.project.dto.dashboard.PimOutputDto;
import com.zeroone.star.project.dto.dashboard.PimTitleDto;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * <p>
 * 描述：系统首页接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 浅墨
 * @version 1.0.0
 */
public interface DashboardApis {
    /**
     * 获取机关和项目人员
     *
     * @return 查询结果
     */
    JsonVO<List<AgencyProjectStaffDTO>> queryAgencyProjectStaff();

    /**
     * 职称等级查询
     *
     * @return
     */
    JsonVO<PimTitleDto> queryProfessionalRank();

    /**
     * 月均产值
     *
     * @return
     */
    JsonVO<PimOutputDto> queryByMonth();
}
