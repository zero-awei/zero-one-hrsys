package com.zeroone.star.project.vo.sysmanager.rolemanager;

import io.swagger.annotations.ApiModel;
import lombok.Data;

import java.util.List;
@ApiModel("角色菜单显示对象")
@Data
public class RoleMenuVO {
    private int roleId;
    private List<Integer> menuIds;
}
