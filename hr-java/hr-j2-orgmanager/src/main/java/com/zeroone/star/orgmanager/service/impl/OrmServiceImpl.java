package com.zeroone.star.orgmanager.service.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.orgmanager.entity.Orgsector;
import com.zeroone.star.orgmanager.mapper.OrmMapper;
import com.zeroone.star.orgmanager.service.IOrmService;
import com.zeroone.star.project.dto.orgmanager.DeptKqdzDTO;
import com.zeroone.star.project.dto.orgmanager.ModifyDeptInfoDTO;
import com.zeroone.star.project.dto.orgmanager.OrgsectorDTO;
import com.zeroone.star.project.query.orgmanager.DeptKqdzQuery;
import lombok.AllArgsConstructor;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.time.LocalDateTime;

/**
 * <p>
 * 组织信息 服务实现类
 * </p>
 *
 * @author rqs
 * @since 2023-05-19
 */
@Service
@AllArgsConstructor
public class OrmServiceImpl extends ServiceImpl<OrmMapper, Orgsector> implements IOrmService {

    @Autowired
    private OrmMapper ormMapper;

    @Override
    public String saveDept(OrgsectorDTO orgsectorDTO) {
        LocalDateTime localDateTime = LocalDateTime.now();
        Orgsector orgsector = new Orgsector();
        orgsector.setCreatedate(localDateTime);
        orgsector.setUpdatedate(localDateTime);
        orgsector.generateOrgSectorId();
        BeanUtils.copyProperties(orgsectorDTO, orgsector);
        int result = ormMapper.insert(orgsector);
        return Integer.toString(result);
    }

    @Override
    public String updateDeptById(ModifyDeptInfoDTO modifyDeptInfoDTO) {
        int result = ormMapper.updateDeptById(modifyDeptInfoDTO);
        return Integer.toString(result);
    }

    @Override
    public Page<DeptKqdzDTO> listBmKqdz(DeptKqdzQuery kqdzQuery) {
        Page<DeptKqdzDTO> page = new Page<>(kqdzQuery.getPageIndex(), kqdzQuery.getPageSize());
        String ormorgsectorid = kqdzQuery.getOrmorgsectorid();
        Page<DeptKqdzDTO> deptKqdzDTOS = ormMapper.selectBmKqdzListById(page, ormorgsectorid);
        return deptKqdzDTOS;
    }
}
