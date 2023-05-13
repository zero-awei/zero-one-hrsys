package com.zeroone.star.di.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.test.TestDTO;
import com.zeroone.star.project.query.test.TestQuery;
import com.zeroone.star.project.test.TestApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * <p>
 * 描述：TODO
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@RestController
@RequestMapping("test")
public class TestController implements TestApis {

    @ApiOperation(value = "分页查询列表")
    @GetMapping("query-list")
    @Override
    public JsonVO<PageDTO<TestDTO>> queryAll(TestQuery query) {
        return null;
    }
}
