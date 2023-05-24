package com.zeroone.star.project.orgmanager;

import com.zeroone.star.project.dto.orgmanager.OrgsectorDTO;
import com.zeroone.star.project.vo.orgmanager.DeptKqdzVO;
import com.zeroone.star.project.dto.orgmanager.ModifyDeptInfoDTO;
import com.zeroone.star.project.query.orgmanager.KqdzQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

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
    JsonVO<String> addDept(OrgsectorDTO orgsectorDTO);
    /**
     * @Description: 修改指定部门信息
     * @params: [modifyDeptInfoDTO]
     * @return: JsonVO<String>
     * @Author: Rqs
     * @Date: 2023/5/19 23:43
     */
    JsonVO<String> modifyDept(ModifyDeptInfoDTO modifyDeptInfoDTO);

    /**
     * @Description: 查询指定部门考勤地址列表（分页查询）
     * @params: [kqdzQuery] 查询指定部门考勤地址数据对象
     * @return: JsonVO<List<DeptKqdzVO>>
     * @Author: Rqs
     * @Date: 2023/5/19 23:56
     */
    JsonVO<List<DeptKqdzVO>> queryBmKqdzById(KqdzQuery kqdzQuery);
}
