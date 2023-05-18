package com.zeroone.star.common.controller;


import com.zeroone.star.common.service.PimpersonService;
import com.zeroone.star.project.dto.PimpersonDTO;
import com.zeroone.star.project.rqscommon.CommonApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * <p>
 * 人员信息 前端控制器
 * </p>
 *
 * @author rqs
 * @since 2023-05-17
 */
@RestController
@RequestMapping("common")
@Api(tags = "common")
public class PimpersonController implements CommonApis {

    @Resource
    PimpersonService pimpersonService;

    @ApiOperation(value = "政治面貌下拉列表")
    @PostMapping("add-political-affiliation")
    @Override
    public JsonVO<String> addPimperson(PimpersonDTO pimpersonDTO) {
        String zzmm = pimpersonDTO.getZzmm();
        return pimpersonService.savePimperson(zzmm);
    }
}

