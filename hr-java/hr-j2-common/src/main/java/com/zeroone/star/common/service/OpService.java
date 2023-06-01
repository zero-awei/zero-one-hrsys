package com.zeroone.star.common.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.common.entity.Op;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;

import java.util.List;

/**
 * <p>
 * 组织性质 服务类
 * </p>
 *
 * @author abner
 * @since 2023-05-25
 */
public interface OpService extends IService<Op> {
    List<DropdownListOptionDTO> listOp();
}
