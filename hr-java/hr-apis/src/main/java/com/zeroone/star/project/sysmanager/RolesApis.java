package com.zeroone.star.project.sysmanager;

import com.zeroone.star.project.dto.sample.SampleDTO;
import com.zeroone.star.project.dto.sysmanager.RoleDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;

import javax.management.relation.Role;

public interface RolesApis {
    /**
     * 通过编号查询角色
     * @param id 编号
     * @return 查询结果
     */
    JsonVO<RoleDTO> queryById(Integer id);

    /**
     * 删除角色
     * @param dto
     * @return
     */
    JsonVO<ResultStatus>  deleteByName(RoleDTO dto);

    /**
     * 新增一个角色
     * @param dto 数据对象
     * @return
     */
    JsonVO<ResultStatus> addOneRole(RoleDTO dto);

    /**
     * 修改角色
     * @param dto 数据对象
     * @return
     */
    JsonVO<ResultStatus> modifyRole(RoleDTO dto);
}
