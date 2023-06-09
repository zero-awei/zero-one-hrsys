package com.zeroone.star.orgmanager.controller;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.orgmanager.entity.TOrmduty;
import com.zeroone.star.orgmanager.mapper.TOrmdutyMapper;
import com.zeroone.star.orgmanager.service.ITOrmdutyService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.dto.DataTransCallBack;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j3.dto.AddPositionDTO;
import com.zeroone.star.project.j3.dto.DeletePositionDTO;
import com.zeroone.star.project.j3.dto.ExportDTO;
import com.zeroone.star.project.j3.dto.JobDTO;
import com.zeroone.star.project.j3.dto.orgmanager.JobTitleDTO;
import com.zeroone.star.project.j3.orgmanager.JobSetApis;
import com.zeroone.star.project.j3.query.JobByNameQuery;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

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
public class JobSetController implements JobSetApis {
    @Resource
    ITOrmdutyService itOrmdutyService;
    @Resource
    TOrmdutyMapper tOrmdutyMapper;
    @Resource
    private FastDfsClientComponent fastDfsClientComponent;


    @Value("${fastdfs.nginx-servers}")
    private String fileServerUrl;


    @Resource
    EasyExcelComponent component;
    @Resource
    private ITOrmdutyService service;

    @GetMapping("expor-all-jobs")
    @ApiOperation("导出所有职务")
    @Override
    public JsonVO<ExportDTO> exportAllJobs() throws Exception {
        //查询数据
        List<TOrmduty> tOrmduties = service.getBaseMapper().selectList(null);
        // 创建输出流
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        // 导出数据到输出流
        component.export("测试", out, TOrmduty.class, tOrmduties);
        //上传FastDfs
        FastDfsFileInfo fastDfsFileInfo = fastDfsClientComponent.uploadFile(out.toByteArray(), "xlsx");
        System.out.println(fastDfsFileInfo.toString());
        //验证
        if (fastDfsFileInfo == null) {
            return JsonVO.fail(null);
        }
        // 返回下载地址
        ExportDTO exportDTO = new ExportDTO();
        exportDTO.setUrl(fastDfsClientComponent.fetchUrl(fastDfsFileInfo, "http://", true));
        System.out.println(exportDTO.toString());

        return JsonVO.success(exportDTO);
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
        //调用service执行逻辑
        service.importExcelData(fastDfsFileInfo);


        // 返回下载地址
        return JsonVO.success("导入成功");
    }

    @GetMapping("queryJobList")
    @ApiOperation("查询职务")
    @Override
    public JsonVO<PageDTO<JobTitleDTO>> queryJobTitleList(PageQuery pageQuery) {
        Page<TOrmduty> tOrmdutyPage = new Page<>(pageQuery.getPageIndex(), pageQuery.getPageSize());
        Page<JobTitleDTO> jobTitleDTOPage = new Page<>(pageQuery.getPageIndex(), pageQuery.getPageSize());
        LambdaQueryWrapper<TOrmduty> queryWrapper = new LambdaQueryWrapper<>();
        // 默认按序号升序排序职务 后续增加可以按照编号 姓名 修改时间排序
        queryWrapper.orderByAsc(TOrmduty::getXh);
        itOrmdutyService.page(tOrmdutyPage, queryWrapper);
        //对象拷贝
        BeanUtils.copyProperties(tOrmdutyPage, jobTitleDTOPage, "records");
        List<TOrmduty> records = tOrmdutyPage.getRecords();
        List<JobTitleDTO> dtoList = records.stream().map((item) -> {
            JobTitleDTO jobTitleDTO = new JobTitleDTO();
            //对象拷贝
            BeanUtils.copyProperties(item, jobTitleDTO);
            jobTitleDTO.setUpdatedate(item.getUpdatedate().toString());
            return jobTitleDTO;
        }).collect(Collectors.toList());
        jobTitleDTOPage.setRecords(dtoList);
        return JsonVO.create(PageDTO.create(jobTitleDTOPage, JobTitleDTO.class), ResultStatus.SUCCESS);
    }

    @PutMapping("modifyJobTitles/{ormdutyid}")
    @ApiOperation("更新若干职务信息")
    @Override
    public JsonVO<Boolean> modifyJobTitle(@PathVariable String ormdutyid, @RequestBody JobTitleDTO jobTitleDTO) {

        TOrmduty tOrmduty = new TOrmduty();
        tOrmduty.setOrmdutyid(ormdutyid);
        tOrmduty.setUpdatedate(LocalDateTime.now());
        tOrmduty.setFglx(jobTitleDTO.getFglx());
        tOrmduty.setXh(jobTitleDTO.getXh());
        tOrmduty.setOrmdutyname(jobTitleDTO.getOrmdutyname());
        boolean res = itOrmdutyService.updateByOrmdutyId(tOrmduty);
        return res ? JsonVO.success(res) : JsonVO.fail(res);
    }

    @GetMapping("query-by-name")
    @ApiOperation("通过名称查找职位详情")
    @Override
    public JsonVO<PageDTO<JobDTO>> queryJobByName(JobByNameQuery condition) {
        return JsonVO.success(itOrmdutyService.listJobByName(condition));
    }

    @DeleteMapping("delete-position")
    @ApiOperation("删除职务信息(支持批量)")
    @Override
    public JsonVO<Boolean> DeletePosition(@RequestBody DeletePositionDTO deletePositionDTO) {
        boolean res = itOrmdutyService.deleteByOrmdutyIds(deletePositionDTO.getPositionId());

        return res ? JsonVO.success(res) : JsonVO.fail(res);
    }


    @PostMapping("add-position")
    @ApiOperation("批量新增职务信息(支持批量)")
    @Override
    public JsonVO<Boolean> AddPosition(@RequestBody JobTitleDTO jobTitleDTO) {
        TOrmduty tOrmduty = new TOrmduty();
        tOrmduty.setOrmdutyname(jobTitleDTO.getOrmdutyname());
        tOrmduty.setXh(jobTitleDTO.getXh());
        tOrmduty.setFglx(jobTitleDTO.getFglx());
        tOrmduty.setOrmdutyid(jobTitleDTO.getOrmdutyid());
        tOrmduty.setCreatedate(LocalDateTime.now());
        tOrmduty.setUpdatedate(LocalDateTime.now());
        tOrmduty.setCreateman("1944DE89-8E28-4D10-812C-CAEEAAE8A927");
        tOrmduty.setUpdateman("1944DE89-8E28-4D10-812C-CAEEAAE8A927");
        boolean res = itOrmdutyService.save(tOrmduty);
        return res ? JsonVO.success(res) : JsonVO.fail(res);
    }

    @Override
    public JsonVO<ExportDTO> exportAllOrgs() {
        return null;
    }


}

