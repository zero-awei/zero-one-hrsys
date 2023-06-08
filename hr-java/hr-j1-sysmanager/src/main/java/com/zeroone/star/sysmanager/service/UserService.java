package com.zeroone.star.sysmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.usermanager.UserDTO;
import com.zeroone.star.project.dto.sysmanager.userrolemanager.UserRoleDTO;
import com.zeroone.star.project.query.sysmanager.usermanager.UserConditionalQuery;
import com.zeroone.star.project.query.sysmanager.usermanager.UserQuery;
import com.zeroone.star.project.vo.sysmanager.UserVO;
import com.zeroone.star.sysmanager.entity.User;

/**
 * <p>
 * 用户表 服务类
 * </p>
 *
 * @author axiao
 * @since 2023-05-25
 */
public interface UserService extends IService<User> {

    PageDTO<UserVO> listAllUsers(UserQuery query);

    PageDTO<UserVO> selectUser(UserConditionalQuery condition);

    Boolean saveUser(UserDTO dto);

    Boolean removeUser(String id);

    Boolean updateUser(UserDTO dto);

    Boolean assignRole(UserRoleDTO dto);

    Boolean updateStatus(String id);
}
