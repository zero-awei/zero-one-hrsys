package com.zeroone.star.orgmanager.service.impl;

import com.zeroone.star.orgmanager.entity.Ormorginfo;
import com.zeroone.star.orgmanager.mapper.OrmMapper;
import com.zeroone.star.orgmanager.service.IOrmService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.orgmanager.DeptInfoDTO;
import com.zeroone.star.project.vo.orgmanager.DeptKqdzVO;
import com.zeroone.star.project.dto.orgmanager.ModifyDeptInfoDTO;
import com.zeroone.star.project.query.orgmanager.KqdzQuery;
import com.zeroone.star.project.vo.JsonVO;
import lombok.AllArgsConstructor;
import org.springframework.stereotype.Service;

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
public class OrmServiceImpl extends ServiceImpl<OrmMapper, Ormorginfo> implements IOrmService {

    @Override
    public JsonVO<String> saveDept(DeptInfoDTO deptInfoDTO) {
        return null;
    }

    @Override
    public JsonVO<String> updateDept(ModifyDeptInfoDTO modifyDeptInfoDTO) {
        return null;
    }

    @Override
    public List<DeptKqdzVO> listBmKqdz(KqdzQuery kqdzQuery) {
        return null;
    }


}
