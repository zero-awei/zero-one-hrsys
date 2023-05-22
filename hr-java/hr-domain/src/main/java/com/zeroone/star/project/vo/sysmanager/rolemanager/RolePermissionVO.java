package com.zeroone.star.project.vo.sysmanager.rolemanager;

import io.swagger.annotations.ApiModel;
import lombok.Data;

import java.util.List;
@ApiModel("角色权限显示对象")
@Data
public class RolePermissionVO {
    private int roleId;
    private List<Integer> permissionIds;

}
