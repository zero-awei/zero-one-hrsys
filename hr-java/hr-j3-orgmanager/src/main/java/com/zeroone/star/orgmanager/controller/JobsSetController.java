package com.zeroone.star.orgmanager.controller;

import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j3.dto.ExportDTO;
import com.zeroone.star.project.j3.dto.JobDTO;
import com.zeroone.star.project.j3.dto.orgmanager.JobTitleDTO;
import com.zeroone.star.project.j3.orgmanager.JobSetApis;
import com.zeroone.star.project.j3.query.JobByNameQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
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
    @Resource
    private FastDfsClientComponent fastDfsClientComponent;

    @Value("${fastdfs.nginx-servers}")
    private String fileServerUrl;

    @GetMapping("expor-all-jobs")
    @ApiOperation("导出所有职务")
    @Override
    public JsonVO<ExportDTO> exportAllJobs() {
        return null;
    }

    @SneakyThrows
    @PostMapping("import-jobs")
    @ApiOperation("导入职务")
    @Override
    public JsonVO<String> importJobs(MultipartFile file) {
        // 获取文件的后缀名
        String fileName = file.getOriginalFilename();
        String suffix = fileName.substring(fileName.lastIndexOf(".") + 1);
        // 开始上传文件
        FastDfsFileInfo fastDfsFileInfo = fastDfsClientComponent.uploadFile(file.getBytes(), suffix);
        // 验证上传结果
        if (fastDfsFileInfo == null) {
            return JsonVO.fail(null);
        }
        // 返回下载地址
        return JsonVO.success(fastDfsClientComponent.fetchUrl(fastDfsFileInfo, "http://" + fileServerUrl, true));
    }
    @GetMapping("queryJobList")
    @ApiOperation("查询职务")
    @Override
    public JsonVO<PageDTO<JobTitleDTO>> queryJobTitleList() {
        return null;
    }

    @PutMapping("modify-jobTitles")
    @ApiOperation("更新若干职务信息")
    @Override
    public JsonVO<Boolean> modifyJobTitle(List<JobTitleDTO> ids) {
        return JsonVO.success(true);
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

