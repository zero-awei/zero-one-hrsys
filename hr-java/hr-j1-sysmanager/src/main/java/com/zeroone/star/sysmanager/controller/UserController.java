package com.zeroone.star.sysmanager.controller;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.usermanager.UserDTO;
import com.zeroone.star.project.query.sysmanager.usermanager.UserQuery;
import com.zeroone.star.project.sysmanager.UserAPis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

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
public class UserController implements UserAPis {

    @ApiOperation(value = "分页查询所有用户")
    @GetMapping("query_all")
    @Override
    public JsonVO<PageDTO<UserDTO>> listAllUsers(UserQuery condition) {
        return null;
    }

    @ApiOperation(value = "用编号查询用户")
    @GetMapping("query_user")
    @Override
    public JsonVO<PageDTO<UserDTO>> queryUser(@RequestParam String id) {
        return null;
    }

    @ApiOperation(value = "添加用户")
    @PostMapping("add")
    @Override
    public JsonVO<String> addUser(UserDTO dto) {
        return null;
    }

    @ApiOperation(value = "删除用户")
    @DeleteMapping("delete")
    @Override
    public JsonVO<String> deleteUser(@RequestParam String id) {
        return null;
    }

    @ApiOperation(value = "修改用户")
    @PutMapping("modify")
    @Override
    public JsonVO<String> modifyUser(UserDTO dto) {
        return null;
    }

    @ApiOperation(value = "修改状态")
    @PutMapping("modifyStatus")
    @Override
    public JsonVO<String> modifyStatus(@RequestParam String id) {
        return null;
    }
}

