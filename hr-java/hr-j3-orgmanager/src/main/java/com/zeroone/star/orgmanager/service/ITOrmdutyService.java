package com.zeroone.star.orgmanager.service;

import com.zeroone.star.orgmanager.entity.TOrmduty;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;

/**
 * <p>
 * 职务管理 服务类
 * </p>
 *
 * @author H
 * @since 2023-05-25
 */
public interface ITOrmdutyService extends IService<TOrmduty> {

    void importExcelData(FastDfsFileInfo fastDfsFileInfo) throws Exception;

}
