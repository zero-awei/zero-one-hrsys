package com.zeroone.star.project.orgmanager;

import com.zeroone.star.project.dto.orgmanager.DeptInfoDTO;
import com.zeroone.star.project.dto.orgmanager.ModifyDeptInfoDTO;
import com.zeroone.star.project.query.dashboard.EducationQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * 描述：部门信息接口
 * 文件名：OrgmanagerApis
 * 创建者：rqs
 * 创建时间：2023/5/19 21:07
 */
public interface OrgmanagerApis {
    /**
     * @Description: 新增部门
     * @params: [deptInfoDTO]
     * @return: JsonVO<String>
     * @Author: Rqs
     * @Date: 2023/5/19 23:43
     */
    JsonVO<String> addDept(DeptInfoDTO deptInfoDTO);
    /**
     * @Description: 修改指定部门信息
     * @params: [modifyDeptInfoDTO]
     * @return: JsonVO<jString>
     * @Author: Rqs
     * @Date: 2023/5/19 23:43
     */
    JsonVO<String> modifyDept(ModifyDeptInfoDTO modifyDeptInfoDTO);
}
