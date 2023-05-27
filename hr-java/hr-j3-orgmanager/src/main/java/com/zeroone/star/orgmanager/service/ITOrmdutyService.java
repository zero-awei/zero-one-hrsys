package com.zeroone.star.orgmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.orgmanager.entity.TOrmduty;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j3.dto.JobDTO;
import com.zeroone.star.project.j3.query.JobByNameQuery;

/**
 * <p>
 * 职务管理 服务类
 * </p>
 *
 * @author breezelr
 * @since 2023-05-27
 */
public interface ITOrmdutyService extends IService<TOrmduty> {

    /**
     * 通过名称查找职位详情
     * @param condition 关键字和页面信息
     * @return 查询结果
     */
    PageDTO<JobDTO> listJobByName(JobByNameQuery condition);

}
