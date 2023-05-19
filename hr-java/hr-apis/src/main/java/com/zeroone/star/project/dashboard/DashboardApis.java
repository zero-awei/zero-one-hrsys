package com.zeroone.star.project.dashboard;

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
}
