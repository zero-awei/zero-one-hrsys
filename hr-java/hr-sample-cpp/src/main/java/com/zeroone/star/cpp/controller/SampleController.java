package com.zeroone.star.cpp.controller;

import cn.hutool.core.bean.BeanUtil;
import com.zeroone.star.cpp.service.SampleService;
import com.zeroone.star.project.cpp.SampleApis;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.cpp.SampleDTO;
import com.zeroone.star.project.query.cpp.SampleQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;

/**
 * <p>
 * 前端控制器
 * </p>
 * @author awei
 * @since 2023-05-06
 */
@RestController
@RequestMapping("sample")
@Api(tags = "示例接口")
@Validated
public class SampleController implements SampleApis {
    @Resource
    SampleService service;

    @GetMapping("query-all")
    @ApiOperation(value = "分页查询")
    @Override
    public JsonVO<PageDTO<SampleDTO>> queryAll(SampleQuery query) {
        return service.get(BeanUtil.beanToMap(query,false,true));
    }

    @PostMapping("add")
    @ApiOperation(value = "新增数据")
    @Override
    public JsonVO<Long> addData(SampleDTO dto) {
        return service.post(dto);
    }

    @PutMapping("modify")
    @ApiOperation(value = "修改数据")
    @Override
    public JsonVO<Long> modifyData(SampleDTO dto) {
        return service.put(dto);
    }

    @DeleteMapping("remove")
    @ApiOperation(value = "删除数据")
    @Override
    public JsonVO<Long> removeData(SampleDTO dto) {
        return service.delete(dto);
    }
}

