package com.zeroone.star.common.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.common.entity.TOrgsector;
import com.zeroone.star.common.mapper.TOrgsectorMapper;
import com.zeroone.star.common.service.ITOrgsectorService;
import com.zeroone.star.project.j3.dto.DropdownListDTO;
import com.zeroone.star.project.j3.query.common.SectorNameQuery;
import org.apache.commons.lang.StringUtils;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 组织部门 服务实现类
 * </p>
 *
 * @author breezelr
 * @since 2023-05-27
 */
@Service
public class TOrgsectorServiceImpl extends ServiceImpl<TOrgsectorMapper, TOrgsector> implements ITOrgsectorService {


    @Override
    public List<DropdownListDTO> listSectorName(SectorNameQuery sectorNameQuery) {
        LambdaQueryWrapper<TOrgsector> queryWrapper = new LambdaQueryWrapper<>();
        queryWrapper.like(StringUtils.isNotBlank(sectorNameQuery.getName()),TOrgsector::getOrgsectorname,sectorNameQuery.getName());
        queryWrapper.eq(StringUtils.isNotBlank(sectorNameQuery.getOrgId()),TOrgsector::getOrgid,sectorNameQuery.getOrgId());
        List<TOrgsector> tOrgsectors = baseMapper.selectList(queryWrapper);
        List<DropdownListDTO> list = new ArrayList<>();
        for (TOrgsector i : tOrgsectors){
            DropdownListDTO dto = new DropdownListDTO();
            dto.setValue(i.getOrgsectorname());
            dto.setKey(i.getOrgsectorid());
            list.add(dto);
        }
        return list;
    }
}
