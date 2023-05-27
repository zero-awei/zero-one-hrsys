package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.usermanager.UserDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.sysmanager.usermanager.UserQuery;
import com.zeroone.star.project.sysmanager.UserAPis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.service.IUserService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;

/**
 * <p>
 * 用户表 前端控制器
 * </p>
 *
 * @author axiao
 * @since 2023-05-22
 */
@RestController
@Api(tags = "用户管理")
@RequestMapping("/user")
@Validated
public class UserController implements UserAPis {

    @Resource
    IUserService userService;

    @ApiOperation(value = "分页查询所有用户")
    @GetMapping("query_all")
    @Override
    public JsonVO<PageDTO<UserDTO>> queryAllUsers(PageQuery pageInfo) {
        return JsonVO.success(userService.listAllUsers(pageInfo));
    }

    @ApiOperation(value = "模糊查询用户")
    @GetMapping("query_user")
    @Override
    public JsonVO<PageDTO<UserDTO>> queryUser(UserQuery condition) {
        return JsonVO.success(userService.selectUser(condition));
    }

    @ApiOperation(value = "添加用户")
    @PostMapping("add")
    @Override
    public JsonVO<Boolean> addUser(@Validated UserDTO dto) {
        return  JsonVO.success(userService.saveUser(dto));
    }

    @ApiOperation(value = "删除用户")
    @DeleteMapping("delete")
    @Override
    public JsonVO<Boolean> deleteUser(String id) {
        return null;
    }

    @ApiOperation(value = "修改用户")
    @PutMapping("modify")
    @Override
    public JsonVO<Boolean> modifyUser(UserDTO dto) {
        return null;
    }

    @ApiOperation(value = "修改状态")
    @PutMapping("modifyStatus")
    @Override
    public JsonVO<Boolean> modifyStatus(@RequestParam String id) {
        return null;
    }
}

