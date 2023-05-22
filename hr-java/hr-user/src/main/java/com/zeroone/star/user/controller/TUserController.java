package com.zeroone.star.user.controller;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.user.UserDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.sysmanager.UserQuery;
import com.zeroone.star.project.sysmanager.UserAPis;
import com.zeroone.star.project.vo.JsonVO;
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
@Api(tags = "用户管理接口")
@Validated
public class TUserController implements UserAPis {

    @ApiOperation(value = "分页查询所有用户")
    @GetMapping("query_all")
    @Override
    public JsonVO<PageDTO<UserDTO>> listAllUsers(UserQuery condition) {
        return null;
    }

    @ApiOperation(value = "用编号查询用户")
    @GetMapping("query_user")
    @Override
    public JsonVO<PageDTO<UserDTO>> queryUser(int id) {
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
    public JsonVO<String> deleteUser(String id) {
        return null;
    }

    @ApiOperation(value = "修改用户")
    @PutMapping("modify")
    @Override
    public JsonVO<String> modifyUser(UserDTO dto) {
        return null;
    }
}

