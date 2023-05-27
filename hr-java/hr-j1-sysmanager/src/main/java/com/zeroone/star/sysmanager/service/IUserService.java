package com.zeroone.star.sysmanager.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.usermanager.UserDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.sysmanager.usermanager.UserQuery;
import com.zeroone.star.sysmanager.entity.User;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 * 用户表 服务类
 * </p>
 *
 * @author axiao
 * @since 2023-05-25
 */
public interface IUserService extends IService<User> {

    PageDTO<UserDTO> listAllUsers(PageQuery pageInfo);

    PageDTO<UserDTO> selectUser(UserQuery condition);

    Boolean saveUser(UserDTO dto);
}
