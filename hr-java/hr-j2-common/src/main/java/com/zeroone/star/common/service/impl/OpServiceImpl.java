package com.zeroone.star.common.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.common.entity.Op;
import com.zeroone.star.common.mapper.OpMapper;
import com.zeroone.star.common.service.OpService;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 组织性质 服务实现类
 * </p>
 *
 * @author abner
 * @since 2023-05-25
 */
@Service
public class OpServiceImpl extends ServiceImpl<OpMapper, Op> implements OpService {
    @Resource
    private OpMapper mapper;
    @Override
    public List<DropdownListOptionDTO> listOp() {
        return mapper.listOp();
    }
}
