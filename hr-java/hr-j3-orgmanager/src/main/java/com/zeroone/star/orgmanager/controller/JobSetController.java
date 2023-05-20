package com.zeroone.star.orgmanager.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j3.dto.AllJobsDTO;
import com.zeroone.star.project.j3.dto.ExportDTO;
import com.zeroone.star.project.j3.dto.JobDTO;
import com.zeroone.star.project.j3.orgmanager.JobSetApis;
import com.zeroone.star.project.j3.query.JobByNameQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * ClassName: JobSetController
 * Description:
 *
 * @Author LR
 * @Create 2023/5/20 13:33
 * @Version 1.0
 */
@RestController
@RequestMapping("jobset")
@Api(tags = "职位信息设置")
public class JobSetController implements JobSetApis {

    @Override
    public JsonVO<ExportDTO> exportAllJobs() {
        return null;
    }

    @Override
    public int importJobs(List<AllJobsDTO> jobs) {
        return 0;
    }

    @GetMapping("query-by-name")
    @ApiOperation("通过名称查找职位详情")
    @Override
    public JsonVO<PageDTO<JobDTO>> queryJobByName(JobByNameQuery condition) {
        //测试接收数据
        System.out.println(condition.getName());
        return null;
    }
}
