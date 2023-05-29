package com.zeroone.star.orgmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.orgmanager.entity.Srforgsector;
import com.zeroone.star.orgmanager.mapper.SrforgsectorMapper;
import com.zeroone.star.orgmanager.service.ISrforgsectorService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.orgmanager.DepartmentDTO;
import com.zeroone.star.project.dto.sample.SampleDTO;
import com.zeroone.star.project.query.orgmanager.DepartmentQuery;
import com.zeroone.star.project.query.orgmanager.DeptQuery1;
import com.zeroone.star.project.query.orgmanager.DeptQuery2;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.util.List;


/**
 * @author wxs
 */
@Mapper(componentModel = "spring")
interface MsSrforgsectorMapper {
    /**
     * Srforgsector do 转换 DepartmentDTO dto
     * @param srforgsector do对象
     * @return dto对象
     */
    DepartmentDTO srforgsectorToDepartmentDTO(Srforgsector srforgsector);
}


/**
 * <p>
 * 组织部门 服务实现类
 * </p>
 *
 * @author letian
 * @since 2023-05-21
 */
@Transactional
@Service
public class SrforgsectorServiceImpl extends ServiceImpl<SrforgsectorMapper, Srforgsector> implements ISrforgsectorService {
    @Resource
    private SrforgsectorMapper srforgsectorMapper;
    @Resource
    private MsSrforgsectorMapper msSrforgsectorMapper;
    @Override
    public Boolean removeDept(DeptQuery1 deptQuery1) {
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

    @Override
    public PageDTO<DepartmentDTO> listAllDepartment(DepartmentQuery query) {

        Page<Srforgsector> page = new Page<>(query.getPageIndex(),query.getPageSize());
        LambdaQueryWrapper<Srforgsector> lambdaQueryWrapper = new LambdaQueryWrapper<>();
        lambdaQueryWrapper.orderByAsc(Srforgsector::getOrdervalue);
        if (query.getName() != null){
            lambdaQueryWrapper.like(Srforgsector::getOrgsectorname,query.getName());
        }
        Page<Srforgsector> srforgsectorPage = baseMapper.selectPage(page, lambdaQueryWrapper);
        return PageDTO.create(srforgsectorPage, x -> msSrforgsectorMapper.srforgsectorToDepartmentDTO(x));
    }

}
