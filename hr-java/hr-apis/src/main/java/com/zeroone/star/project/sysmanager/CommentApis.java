package com.zeroone.star.project.sysmanager;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.menumanager.MenuDTO;
import com.zeroone.star.project.dto.sysmanager.rightmanagement.RightDTO;
import com.zeroone.star.project.dto.sysmanager.rolemanager.RoleDTO;
import com.zeroone.star.project.query.sysmanager.rolemanager.RoleQuery;
import com.zeroone.star.project.vo.JsonVO;

import javax.validation.constraints.NotBlank;
import java.util.List;

public interface CommentApis {
    /**
     * 描述：查询菜单结构树
     * @param userId 查询条件
     * @return 查询结果
     */
    JsonVO<List<MenuDTO>> queryMenuTree(@NotBlank(message = "id 不能为空")String userId);

    /**
     * 描述：查询权限结构树
     * @param userId 查询条件
     * @return 查询结果
     */
    JsonVO<List<RightDTO>> queryRightTree(@NotBlank(message = "id 不能为空")String userId);

    /**
     * 描述：分页查询角色列表
     * @param query 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<RoleDTO>> queryListRole(RoleQuery query);
}
