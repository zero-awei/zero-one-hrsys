package com.zeroone.star.common.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.common.entity.Pimperson;
import com.zeroone.star.project.dto.common.StatusListDTO;

import java.util.List;

/**
 * <p>
 * 人员信息 服务类
 * </p>
 *
 * @author wxs
 * @since 2023-05-23
 */
public interface IPimpersonService extends IService<Pimperson> {

    List<StatusListDTO> listEmployeeStatus();
}
