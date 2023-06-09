package com.zeroone.star.orgmanager.service;

import com.zeroone.star.orgmanager.entity.TOrmduty;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.baomidou.mybatisplus.core.conditions.Wrapper;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.orgmanager.entity.TOrmduty;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j3.dto.JobDTO;
import com.zeroone.star.project.j3.query.JobByNameQuery;

import java.util.List;

/**
 * <p>
 * 职务管理 服务类
 * </p>
 *
 * @author H
 * @since 2023-05-25
 */
public interface ITOrmdutyService extends IService<TOrmduty> {
    /**
     * 通过Excel文件导入职务
     * @param fastDfsFileInfo fastDfsFileInfo
     * @Author H_lzu
     * @Date 22:38 2023/6/8
     */
    void importExcelData(FastDfsFileInfo fastDfsFileInfo) throws Exception;

    /**
     * 更新职务信息
     * @param tOrmduty
     * @return
     */
    boolean updateByOrmdutyId(TOrmduty tOrmduty);

    /**
     * 批量删除职务信息
     * @param ids
     * @return
     */
    boolean deleteByOrmdutyIds(List<String> ids);

    /**
     * 通过名称查找职位详情
     * @param condition 关键字和页面信息
     * @return 查询结果
     */
    PageDTO<JobDTO> listJobByName(JobByNameQuery condition);

}
