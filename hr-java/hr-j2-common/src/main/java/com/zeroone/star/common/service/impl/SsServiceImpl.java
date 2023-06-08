package com.zeroone.star.common.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.common.entity.Ss;
import com.zeroone.star.common.mapper.SsMapper;
import com.zeroone.star.common.service.SsService;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 补贴标准 服务实现类
 * </p>
 *
 * @author abner
 * @since 2023-05-25
 */
@Service
public class SsServiceImpl extends ServiceImpl<SsMapper, Ss> implements SsService {
    @Resource
    private SsMapper mapper;
    @Override
    public List<DropdownListOptionDTO> listSs() {
        return mapper.listSs();
    }
}
