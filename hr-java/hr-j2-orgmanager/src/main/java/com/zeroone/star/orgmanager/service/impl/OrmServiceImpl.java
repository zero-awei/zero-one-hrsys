package com.zeroone.star.orgmanager.service.impl;

import com.zeroone.star.orgmanager.entity.Orgsector;
import com.zeroone.star.orgmanager.mapper.OrmMapper;
import com.zeroone.star.orgmanager.service.IOrmService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.orgmanager.OrgsectorDTO;
import com.zeroone.star.project.vo.orgmanager.DeptKqdzVO;
import com.zeroone.star.project.dto.orgmanager.ModifyDeptInfoDTO;
import com.zeroone.star.project.query.orgmanager.KqdzQuery;
import com.zeroone.star.project.vo.JsonVO;
import lombok.AllArgsConstructor;
import org.apache.ibatis.javassist.NotFoundException;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.sql.Timestamp;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Arrays;
import java.util.List;

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
    public List<DeptKqdzVO> listBmKqdz(KqdzQuery kqdzQuery) {
        return null;
    }


}
