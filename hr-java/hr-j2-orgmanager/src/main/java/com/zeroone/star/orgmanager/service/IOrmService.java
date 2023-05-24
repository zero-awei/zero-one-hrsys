package com.zeroone.star.orgmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.orgmanager.entity.Orgsector;
import com.zeroone.star.project.dto.orgmanager.OrgsectorDTO;
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
public interface IOrmService extends IService<Orgsector> {
    @PostMapping("/save-dept")
    String saveDept(OrgsectorDTO orgsectorDTO);

    @PostMapping("/update-dept-by-id")
    JsonVO<String> updateDept(ModifyDeptInfoDTO modifyDeptInfoDTO);

    @GetMapping("/list-bm-kqdz")
    List<DeptKqdzVO> listBmKqdz(KqdzQuery kqdzQuery);
}
