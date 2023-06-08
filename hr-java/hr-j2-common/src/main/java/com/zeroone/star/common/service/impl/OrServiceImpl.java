package com.zeroone.star.common.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.common.entity.Or;
import com.zeroone.star.common.mapper.OrMapper;
import com.zeroone.star.common.service.OrService;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 所属区域 服务实现类
 * </p>
 *
 * @author abner
 * @since 2023-05-25
 */
@Service
public class OrServiceImpl extends ServiceImpl<OrMapper, Or> implements OrService {
    @Resource
    private OrMapper mapper;
    @Override
    public List<DropdownListOptionDTO> listOr() {
        return mapper.listOr();
    }
}
