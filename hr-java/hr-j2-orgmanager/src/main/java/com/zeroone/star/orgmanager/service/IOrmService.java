package com.zeroone.star.orgmanager.service;

import com.zeroone.star.orgmanager.entity.Ormorginfo;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.orgmanager.DeptInfoDTO;
import com.zeroone.star.project.vo.orgmanager.DeptKqdzVO;
import com.zeroone.star.project.dto.orgmanager.ModifyDeptInfoDTO;
import com.zeroone.star.project.query.orgmanager.KqdzQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;

import java.util.List;

/**
 * <p>
 * 组织信息 服务类
 * </p>
 *
 * @author rqs
 * @since 2023-05-19
 */
public interface IOrmService extends IService<Ormorginfo> {
    @PostMapping("/save-dept")
    JsonVO<String> saveDept(DeptInfoDTO deptInfoDTO);

    @PostMapping("/update-dept-by-id")
    JsonVO<String> updateDept(ModifyDeptInfoDTO modifyDeptInfoDTO);

    @GetMapping("/list-bm-kqdz")
    List<DeptKqdzVO> listBmKqdz(KqdzQuery kqdzQuery);
}
