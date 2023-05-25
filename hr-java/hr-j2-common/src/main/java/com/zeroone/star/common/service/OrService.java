package com.zeroone.star.common.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.common.entity.Or;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;

import java.util.List;

/**
 * <p>
 * 所属区域 服务类
 * </p>
 *
 * @author abner
 * @since 2023-05-25
 */
public interface OrService extends IService<Or> {
    List<DropdownListOptionDTO> listOr();
}
