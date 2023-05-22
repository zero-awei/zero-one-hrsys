package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.RightsDTO;
import com.zeroone.star.project.query.sysmanager.RightsQuery;
import com.zeroone.star.project.sysmanager.RightsApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

/**
 * 权限
 *
 * @author authoralankay
 */
@RestController
@RequestMapping("/rights")
public class RightsController implements RightsApis {
    @ApiOperation(value = "分页查询列表")
    @GetMapping("/query-list")
    @Override
    public JsonVO<PageDTO<RightsDTO>> queryAll(RightsQuery query) {
        return null;
    }

    @ApiOperation(value = "分页查询列表")
    @GetMapping("/query-list")
    @Override
    public JsonVO<PageDTO<RightsDTO>> queryAll(String query) {
        return null;
    }

    @ApiOperation(value = "增加权限")
    @PostMapping("/add-rights")
    @Override
    public JsonVO<String> addRights(RightsDTO dto) {
        return null;
    }

    @ApiOperation(value = "修改权限")
    @PostMapping("/modify-rights")
    @Override
    public JsonVO<RightsDTO> modifyRights(RightsDTO dto) {
        return null;
    }

    @ApiOperation(value = "删除权限")
    @DeleteMapping ("/remove-rights")
    @Override
    public JsonVO<String> removeRights(RightsDTO dto) {
        return null;
    }

}
