package com.zeroone.star.project.j3.orgmanager.dataset;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.orgmanager.dataset.JobDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * ClassName: JobSetApis
 * Description: 职位设置API接口定义
 *
 * @Author LR
 * @Create 2023/5/18 18:19
 * @Version 1.0
 */
public interface JobSetApis {
    /**
     * 通过名称查询指定职务详情
     * 表 t_ormduty
     * @param name 搜索框关键字
     * @return 搜索出的 JsonVO<PageDTO<JobDTO>>
     */
    JsonVO<PageDTO<JobDTO>> QueryJobByName(String name);
}
