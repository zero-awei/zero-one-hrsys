package com.zeroone.star.common.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.common.entity.TSrforgsector;
import com.zeroone.star.common.mapper.TSrforgsectorMapper;
import com.zeroone.star.common.service.ITSrforgsectorService;
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
 * @author lr
 * @since 2023-05-29
 */
@Service
public class TSrforgsectorServiceImpl extends ServiceImpl<TSrforgsectorMapper, TSrforgsector> implements ITSrforgsectorService {

    @Override
    public List<DropdownListDTO> listSectorName(SectorNameQuery sectorNameQuery) {
        //构造条件
        LambdaQueryWrapper<TSrforgsector> queryWrapper = new LambdaQueryWrapper<>();
        queryWrapper.like(StringUtils.isNotBlank(sectorNameQuery.getName()),TSrforgsector::getOrgsectorname,sectorNameQuery.getName());
        queryWrapper.eq(StringUtils.isNotBlank(sectorNameQuery.getOrgId()),TSrforgsector::getOrgid,sectorNameQuery.getOrgId());
        queryWrapper.select(TSrforgsector::getOrgsectorname,TSrforgsector::getOrgsectorid);
        //执行查询
        List<TSrforgsector> tSrforgsectors = baseMapper.selectList(queryWrapper);
        //转换成所需要的内容
        List<DropdownListDTO> list = new ArrayList<>();
        for (TSrforgsector i : tSrforgsectors){
            DropdownListDTO dto = new DropdownListDTO();
            dto.setValue(i.getOrgsectorname());
            dto.setKey(i.getOrgsectorid());
            list.add(dto);
        }
        return list;
    }
}
