package com.zeroone.star.sysmanager.controller;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.usermanager.UserDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.sysmanager.usermanager.UserQuery;
import com.zeroone.star.project.sysmanager.UserAPis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.sysmanager.entity.User;
import com.zeroone.star.sysmanager.service.IUserService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

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
        List<User> list = userService.list(new LambdaQueryWrapper<User>().eq(User::getUsername, dto.getUsername()));
        if(list.size()>0){
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(),"已经有该用户了");
        }
        return  userService.saveUser(dto)? JsonVO.success(true):JsonVO.fail(false);
    }

    @ApiOperation(value = "删除用户")
    @DeleteMapping("delete")
    @Override
    public JsonVO<Boolean> deleteUser(@RequestParam String id) {
        return userService.removeUser(id)? JsonVO.success(true):JsonVO.fail(false);
    }

    @ApiOperation(value = "修改用户")
    @PutMapping("modify")
    @Override
    public JsonVO<Boolean> modifyUser(@Validated UserDTO dto) {
        return userService.updateUser(dto)?JsonVO.success(true):JsonVO.fail(false);
    }

    @ApiOperation(value = "修改状态")
    @PutMapping("modifyStatus")
    @Override
    public JsonVO<Boolean> modifyStatus(@RequestParam String id) {
        return userService.updateStatus(id) ? JsonVO.success(true):JsonVO.fail(false);
    }
}
