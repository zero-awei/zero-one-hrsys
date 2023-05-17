package com.zeroone.star.common.controller;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.statuslist.StatusListDto;
import com.zeroone.star.project.emplist.StatusApi;
import com.zeroone.star.project.query.statuslist.StatusListQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/employee")
public class StatusListController implements StatusApi {
    @ApiOperation(value = "员工状态列表")
    @GetMapping("/status-list")
    @Override
    public JsonVO<PageDTO<StatusListDto>> queryAll(StatusListQuery query) {
        return null;
    }
}
