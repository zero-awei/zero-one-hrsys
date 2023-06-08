package com.zeroone.star.common.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.common.entity.Dt;
import com.zeroone.star.common.mapper.DtMapper;
import com.zeroone.star.common.service.DtService;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 部门类型 服务实现类
 * </p>
 *
 * @author abner
 * @since 2023-05-25
 */
@Service
public class DtServiceImpl extends ServiceImpl<DtMapper, Dt> implements DtService {
    @Resource
    private DtMapper mapper;
    @Override
    public List<DropdownListOptionDTO> listDt() {
        return mapper.listDt();
    }
}
