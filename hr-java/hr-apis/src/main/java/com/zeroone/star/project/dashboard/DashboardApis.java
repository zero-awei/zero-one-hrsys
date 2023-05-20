package com.zeroone.star.project.dashboard;

<<<<<<< HEAD
import com.zeroone.star.project.dto.dashboard.AgencyProjectStaffDTO;
import com.zeroone.star.project.dto.dashboard.PimOutputDTO;
import com.zeroone.star.project.dto.dashboard.PimTitleDTO;
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
    JsonVO<PimTitleDTO> queryProfessionalRank();

    /**
     * 月均产值
     *
     * @return
     */
    JsonVO<PimOutputDTO> queryByMonth();
=======
import com.zeroone.star.project.query.dashboard.EducationQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * 描述：系统首页接口
 * 文件名：DashboardApis
 * 创建者：rqs
 * 创建时间：2023/5/18 21:15
 */
public interface DashboardApis {
    /**
     * @Description: 查询学历分布
     * @params: []
     * @return: JsonVO<EducationQuery>
     * @Author: Rqs
     * @Date: 2023/5/18 22:47
     */
    JsonVO<EducationQuery> queryEducationDistribution();
>>>>>>> origin/j2-rqs
}
