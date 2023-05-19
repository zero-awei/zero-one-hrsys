package com.zeroone.star.orgmanager.service;

import com.zeroone.star.orgmanager.entity.Ormorginfo;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.orgmanager.DeptInfoDTO;
import com.zeroone.star.project.dto.orgmanager.ModifyDeptInfoDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.bind.annotation.PostMapping;

/**
 * <p>
 * 组织信息 服务类
 * </p>
 *
 * @author rqs
 * @since 2023-05-19
 */
public interface IOrmorginfoService extends IService<Ormorginfo> {
    @PostMapping("/saveDept")
    JsonVO<String> saveDept(DeptInfoDTO deptInfoDTO);

    JsonVO<String> updateDept(ModifyDeptInfoDTO modifyDeptInfoDTO);
}
