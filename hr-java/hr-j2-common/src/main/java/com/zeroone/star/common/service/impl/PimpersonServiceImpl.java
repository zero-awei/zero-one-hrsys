package com.zeroone.star.common.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.common.entity.Pimperson;
import com.zeroone.star.common.mapper.PimpersonMapper;
import com.zeroone.star.common.service.IPimpersonService;
import com.zeroone.star.project.dto.common.StatusListDTO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;


/**
 * <p>
 * 人员信息 服务实现类
 * </p>
 *
 * @author wxs
 * @since 2023-05-23
 */
@Service
public class PimpersonServiceImpl extends ServiceImpl<PimpersonMapper, Pimperson> implements IPimpersonService {

    @Resource
    PimpersonMapper pimpersonMapper;

    @Override
    public List<StatusListDTO> listEmployeeStatus() {

        List<StatusListDTO> statusListDTOS =pimpersonMapper.selectEmployeeStatus();
        return statusListDTOS;
    }
}
