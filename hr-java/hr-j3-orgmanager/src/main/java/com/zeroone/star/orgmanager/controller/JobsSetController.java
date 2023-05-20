package com.zeroone.star.orgmanager.controller;

import com.zeroone.star.project.j3.dto.AllJobsDTO;
import com.zeroone.star.project.j3.dto.ExportDTO;
import com.zeroone.star.project.j3.orgmanager.JobSetApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * <p>
 * 描述：TODO
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author H
 * @version 1.0.0
 * @date 2023/5/20 16:48
 */
@RestController
@RequestMapping("jobset")
@Api(tags = "职务设置")
public class JobsSetController implements JobSetApis {
    @GetMapping("expor-all-jobs")
    @ApiOperation("导出所有职务")
    @Override
    public JsonVO<ExportDTO> exportAllJobs() {
        return null;
    }

    @PostMapping("import-jobs")
    @ApiOperation("导入职务")
    @Override
    public JsonVO<Integer> importJobs(List<AllJobsDTO> jobs) {
        return null;
    }
}
