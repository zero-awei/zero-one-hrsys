package com.zeroone.star.orgmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.orgmanager.entity.TOrmduty;
import com.zeroone.star.orgmanager.mapper.TOrmdutyMapper;
import com.zeroone.star.orgmanager.service.ITOrmdutyService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j3.dto.orgmanager.JobTitleDTO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 * 职务管理 服务实现类
 * </p>
 *
 * @author loop
 * @since 2023-05-27
 */
@Service
public class TOrmdutyServiceImpl extends ServiceImpl<TOrmdutyMapper, TOrmduty> implements ITOrmdutyService {

    @Autowired
    TOrmdutyMapper tOrmdutyMapper;
    @Override
    public boolean updateByOrmdutyId(TOrmduty tOrmduty) {
        return tOrmdutyMapper.updateOrmdutyById(tOrmduty);
    }

    @Override
    public boolean deleteByOrmdutyIds(List<String> ids) {
        return tOrmdutyMapper.deleteByOrmdutyids(ids);
    }

}
