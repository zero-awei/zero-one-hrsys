package com.zeroone.star.project.sysmanager;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.usermanager.UserDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.sysmanager.usermanager.UserQuery;
import com.zeroone.star.project.vo.JsonVO;

import javax.validation.constraints.NotBlank;

/**
 * 用户API接口定义
 * @author axiao
 */
public interface UserAPis {
    /**
     * 用户列表
     * @param pageInfo 分页条件
     * @return 查询结果
     */
    JsonVO<PageDTO<UserDTO>> queryAllUsers(PageQuery pageInfo);

    /**
     * 查询用户
     * @param condition 查询条件
     * @return 模糊查询
     */
    JsonVO<PageDTO<UserDTO>> queryUser(UserQuery condition);

    /**
     * 新增用户
     * @param dto 数据对象
     * @return 新增用户的编号
     */
    JsonVO<Boolean> addUser(UserDTO dto);

    /**
     * 删除用户
     * @param id 用户id
     * @return 删除结果
     */
    JsonVO<Boolean> deleteUser(@NotBlank(message = "id 不能为空") String id);

    /**
     * 修改用户
     * @param dto 数据对象
     * @return 修改结果
     */
    JsonVO<Boolean> modifyUser(UserDTO dto);

    /**
     * 修改状态
     * @param id ID
     * @return 修改结果
     */
    JsonVO<Boolean> modifyStatus(@NotBlank(message = "id 不能为空") String id);

}