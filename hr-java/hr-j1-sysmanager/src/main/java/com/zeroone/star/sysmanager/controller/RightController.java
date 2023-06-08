package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.rightmanagement.RightDTO;
import com.zeroone.star.project.query.sysmanager.comment.CommentQuery;
import com.zeroone.star.project.query.sysmanager.rightmanager.RightQuery;
import com.zeroone.star.project.sysmanager.RightApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.service.RightService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

/**
 * The controller of {@link RightApis}, base on {@link RightService}
 *
 * @author authoralankay
 * @see RightApis
 * @see RightService
 */
@RestController
@RequestMapping("/sys-right")
@Api(tags = "权限管理")
public class RightController implements RightApis {

    private RightService rightService;

    public RightController(RightService rightService) {
        this.rightService = rightService;
    }

    @ApiOperation(value = "分页查询列表")
    @GetMapping("/query-list")
    @Override
    public JsonVO<PageDTO<RightDTO>> queryAll(RightQuery query) {
        return rightService.queryAll(query);
    }

    @ApiOperation(value = "模糊查询列表")
    @GetMapping("/query-like")
    @Override
    public JsonVO<PageDTO<RightDTO>> queryLike(CommentQuery query) {
        return rightService.queryLike(query);
    }

    @ApiOperation(value = "增加权限")
    @PostMapping("/add-right")
    @Override
    public JsonVO<Boolean> addRight(RightDTO dto) {
        return rightService.addRight(dto);
    }

    @ApiOperation(value = "修改权限")
    @PostMapping("/modify-right")
    @Override
    public JsonVO<Boolean> modifyRight(RightDTO dto) {
        return rightService.modifyRight(dto);
    }

    @ApiOperation(value = "删除权限")
    @DeleteMapping("/remove-right")
    @Override
    public JsonVO<Boolean> removeRight(@RequestParam String id) {
        return rightService.removeRight(id);
    }

    @ApiOperation(value = "修改状态")
    @PostMapping("/modify-status")
    @Override
    public JsonVO<Boolean> modifyStatus(@RequestParam String id) {
        return rightService.modifyStatus(id);
    }
}
