package com.zeroone.star.project.sysmanager;

import com.zeroone.star.project.dto.sample.SampleDTO;
import com.zeroone.star.project.dto.sysmanager.RoleDTO;
import com.zeroone.star.project.vo.JsonVO;

import javax.management.relation.Role;

public interface RolesApis {
    /**
     * 通过编号查询角色
     * @param id 编号
     * @return 查询结果
     */
    JsonVO<RoleDTO> queryById(Integer id);

    /**
     * 通过角色名字删除
     * @param name
     * @return
     */
    JsonVO<Void>  deleteByName(String name);

    /**
     * 新增一个角色
     * @param id
     * @param name
     * @param keyword
     * @param description
     * @return
     */
    JsonVO<RoleDTO> insertOneRole(Integer id, String name,String keyword,String description);

    /**
     * 修改一个角色
     * @param role
     * @return
     */
    JsonVO<RoleDTO> modifyOneRole(Role role);
}
