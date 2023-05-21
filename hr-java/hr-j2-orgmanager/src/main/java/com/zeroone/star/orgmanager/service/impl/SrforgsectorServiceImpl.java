package com.zeroone.star.orgmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.orgmanager.entity.Srforgsector;
import com.zeroone.star.orgmanager.mapper.SrforgsectorMapper;
import com.zeroone.star.orgmanager.service.ISrforgsectorService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.query.orgmanager.DeptQuery1;
import com.zeroone.star.project.query.orgmanager.DeptQuery2;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 * 组织部门 服务实现类
 * </p>
 *
 * @author letian
 * @since 2023-05-21
 */
@Service
public class SrforgsectorServiceImpl extends ServiceImpl<SrforgsectorMapper, Srforgsector> implements ISrforgsectorService {
    @Resource
    private SrforgsectorMapper srforgsectorMapper;
    @Override
    public Boolean removeDeptById(DeptQuery1 deptQuery1) {
        if (srforgsectorMapper.deleteById(deptQuery1.getOrgSectorId()) > 0) {
            return true;
        }
        return false;
    }

    @Override
    public Boolean removeDepts(DeptQuery2 deptQuery2) {
        if (srforgsectorMapper.deleteDepts(deptQuery2) > 0) {
            return true;
        }
        return false;
    }
}
