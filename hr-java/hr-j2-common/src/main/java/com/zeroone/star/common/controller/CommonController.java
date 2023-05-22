package com.zeroone.star.common.controller;

import com.zeroone.star.common.service.IOrmpostlibService;
import com.zeroone.star.project.common.CommonApis;
import com.zeroone.star.project.dto.common.GwTypeDTO;
import com.zeroone.star.project.dto.common.PostNatureDTO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
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
    @Resource
    private IOrmpostlibService ormpostlibService;
    @ApiOperation(value = "获取岗位分类下拉列表")
    @GetMapping("/query-post-classification")
    @Override
    public JsonVO<List<GwTypeDTO>> queryGwfl() {
        List<GwTypeDTO> list = ormpostlibService.getGwType();
        return JsonVO.success(list);
    }

    @ApiOperation(value = "获取岗位性质下拉列表")
    @GetMapping("/query-post-nature")
    @Override
    public JsonVO<List<PostNatureDTO>> queryPostNature() {
        List<PostNatureDTO> list = ormpostlibService.getPostNature();
        return JsonVO.success(list);
    }
}
