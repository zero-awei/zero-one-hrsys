package com.zeroone.star.common.controller;

import com.zeroone.star.common.service.ZzmmService;
import com.zeroone.star.project.common.CommonApis;
import com.zeroone.star.project.query.common.ZzmmQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * 描述：
 * 文件名：ZzmmController
 * 创建者：rqs
 * 创建时间：2023/5/19 23:13
 */
@RestController
@RequestMapping("common")
@Api(tags = "common")
public class ZzmmController implements CommonApis {

    @Resource
    ZzmmService zzmmService;

    @ApiOperation(value = "政治面貌下拉列表")
    @GetMapping("query-zzmm")
    @Override
    public JsonVO<ZzmmQuery> queryZzmm() {
        return zzmmService.getZzmm();
    }
}
