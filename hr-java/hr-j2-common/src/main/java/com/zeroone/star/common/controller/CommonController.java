package com.zeroone.star.common.controller;

import com.zeroone.star.project.common.CommonApis;
import com.zeroone.star.project.dto.post.GwflDTO;
import com.zeroone.star.project.dto.post.PostNatureDTO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
  * @author：letian
  * @date  2023/5/20
  * @description：岗位分类下拉列表接口、岗位性质下拉列表接口
  * @version: 1.0
*/
@RestController
@RequestMapping("/common")
@Api(tags = "岗位分类下拉列表接口、岗位性质下拉列表接口")
public class CommonController implements CommonApis {

    @ApiOperation(value = "获取岗位分类下拉列表")
    @GetMapping("/query-post-classification")
    @Override
    public JsonVO<List<GwflDTO>> queryGwfl() {
        return null;
    }

    @ApiOperation(value = "获取岗位性质下拉列表")
    @GetMapping("/query-post-nature")
    @Override
    public JsonVO<List<PostNatureDTO>> queryPostNature() {
        return null;
    }
}
