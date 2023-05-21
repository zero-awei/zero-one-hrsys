package com.zeroone.star.sysmanager.controller;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.usermanager.UserDTO;
import com.zeroone.star.project.query.sysmanager.usermanager.UserQuery;
import com.zeroone.star.project.sysmanager.UserAPis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

/**
 * <p>
 * 用户 前端控制器
 * </p>
 *
 * @author axiao
 * @since 2023-05-18
 */
@Slf4j
@RestController
@RequestMapping("/user")
@Api(tags = "用户管理")
@Validated
public class TUserController implements UserAPis {

    @ApiOperation(value = "分页查询所有用户")
    @GetMapping("query-all")
    @Override
    public JsonVO<PageDTO<UserDTO>> listAllUsers(UserQuery condition) {
        return null;
    }

    @ApiOperation(value = "用编号查询用户")
    @GetMapping("query-user")
    @Override
    public JsonVO<PageDTO<UserDTO>> queryUser(int id) {
        return null;
    }

    @ApiOperation(value = "添加用户")
    @PostMapping("add")
    @Override
    public JsonVO<Boolean> addUser(UserDTO dto) {
        return null;
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
}

