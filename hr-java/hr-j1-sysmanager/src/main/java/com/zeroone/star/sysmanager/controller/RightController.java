package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.rightmanagement.RightDTO;
import com.zeroone.star.project.query.sysmanager.rightmanager.RightQuery;
import com.zeroone.star.project.sysmanager.RightApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

/**
 * <p>
 * 描述：权限管理控制层
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author
 * @version 1.0.0
 */

@RestController
@RequestMapping("/right")
@Api(tags = "权限管理")
public class RightController implements RightApis {
    /**
     * 分页查询列表
     * @param query 查询条件
     * @return 查询结果
     */
    @ApiOperation(value = "分页查询列表")
    @GetMapping("/query-list")
    @Override
    public JsonVO<PageDTO<RightDTO>> queryAll(RightQuery query) {
        return null;
    }

    @ApiOperation(value = "分页查询列表")
    @GetMapping("/query-list")
    @Override
    public JsonVO<PageDTO<RightDTO>> queryAll(String query) {
        return null;
    }

    @ApiOperation(value = "增加权限")
    @PostMapping("/add-right")
    @Override
    public JsonVO<Boolean> addRight(RightDTO dto) {
        return null;
    }

    @ApiOperation(value = "修改权限")
    @PostMapping("/modify-right")
    @Override
    public JsonVO<Boolean> modifyRight(RightDTO dto) {
        return null;
    }

    @ApiOperation(value = "删除权限")
    @DeleteMapping ("/remove-right")
    @Override
    public JsonVO<Boolean> removeRight(RightDTO dto) {
        return null;
    }

}
