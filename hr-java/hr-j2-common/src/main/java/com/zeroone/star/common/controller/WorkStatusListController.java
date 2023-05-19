package com.zeroone.star.common.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.statuslist.WorkStatusListDTO;
import com.zeroone.star.project.emplist.WorkStatusApi;
import com.zeroone.star.project.query.statuslist.WorkStatusListQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * @author mwx
 * @version 1.0
 * @description: TODO
 * @date 2023/5/18 10:00
 */
@RestController
@RequestMapping("employee")
public class WorkStatusListController implements WorkStatusApi {

    @Override
    @GetMapping("work-status")
    @ApiOperation(value = "工作状态列表")
    public JsonVO<PageDTO<WorkStatusListDTO>> queryAll(WorkStatusListQuery query) {
        return null;
    }

}
