package com.zeroone.star.common.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.common.entity.Ss;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;

import java.util.List;

/**
 * <p>
 * 补贴类型 服务类
 * </p>
 *
 * @author abner
 * @since 2023-05-25
 */
public interface SsService extends IService<Ss> {
    List<DropdownListOptionDTO> listSs();
}
