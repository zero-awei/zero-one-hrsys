package com.zeroone.star.orgmanager.controller;

import com.zeroone.star.orgmanager.entity.TOrmduty;
import com.zeroone.star.orgmanager.entity.TOrmorginfo;
import com.zeroone.star.orgmanager.service.ITOrmorginfoService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sample.SampleDTO;
import com.zeroone.star.project.j3.dto.DeleteDTO;
import com.zeroone.star.project.j3.dto.ExportDTO;
import com.zeroone.star.project.j3.dto.orgmanager.ModifyOrgAddressDTO;
import com.zeroone.star.project.j3.dto.orgmanager.OrgInfoDTO;
import com.zeroone.star.project.j3.dto.orgmager.OrgAddressDto;
import com.zeroone.star.project.j3.orgmanager.OrgInfoApis;
import com.zeroone.star.project.j3.query.OrgQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.List;

/**
 * <p>
 * 描述：组织信息管接口实现
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author H
 * @version 1.0.0
 * @date 2023/5/20 10:21
 */
@RestController
@RequestMapping("orginfo")
@Api(tags = "组织信息管理")
public class OrgInfoController implements OrgInfoApis {

    @DeleteMapping("remove-org-address")
    @ApiOperation("删除组织地址")
    @Override
    public JsonVO<Boolean> deleteDepAddress(@RequestBody OrgAddressDto orgAddressDto) {
        return null;
    }

    @PutMapping("modify-org-info")
    @ApiOperation("修改组织信息")
    @Override
    public JsonVO<Boolean> modifyOrgInfo(@ModelAttribute OrgInfoDTO orgInfoDTO) {
        return null;
    }

    @PutMapping("modify-org-address")
    @ApiOperation("修改组织地址信息（导入的地址也通过这个接口更新）")
    @Override
    public JsonVO<Boolean> modifyOrgAddress(@RequestBody List<ModifyOrgAddressDTO> modifyOrgAddressDTOs) {
        return null;
    }

    @DeleteMapping("remove-org-info")
    @ApiOperation("删除组织信息（支持批量）")
    @Override
    public JsonVO<Boolean> removeOrgData(DeleteDTO ids) {
        return JsonVO.success(true);
    }

    @DeleteMapping("delete-org-address")
    @ApiOperation("删除指定组织地址信息（支持批量）")
    @Override
    public JsonVO<Boolean> deleteOrgAddress(@RequestBody OrgAddressDto ids) {
        return null;
    }

    @GetMapping("export-org-address")
    @ApiOperation("导出指定组织地址信息")
    @Override
    public JsonVO<Boolean> exportOrgAddress(OrgAddressDto orgAddressDto) {

        return null;
    }

    @PutMapping("add-org-info")
    @ApiOperation("添加组织00")
    @Override
    public JsonVO<Boolean> addOryData(@RequestBody OrgInfoDTO orgInfoDTO) {
        return JsonVO.success(true);
    }

    @Override
    public JsonVO<PageDTO<SampleDTO>> queryAllOrg(OrgQuery condition) {
        return null;
    }
    @Resource
    private FastDfsClientComponent fastDfsClientComponent;

    @Value("${fastdfs.nginx-servers}")
    private String fileServerUrl;
    @Autowired
    private ITOrmorginfoService service;
    @Resource
    EasyExcelComponent component;
    @GetMapping("expor-all-org")
    @ApiOperation("导出所有组织")
    @Override
    public JsonVO<ExportDTO> exportOrg() throws Exception {
        //查询数据
        List<TOrmorginfo> tormorginfos = service.getBaseMapper().selectList(null);
        // 创建输出流
         ByteArrayOutputStream out = new ByteArrayOutputStream();
        // 导出数据到输出流
        component.export("测试", out, TOrmorginfo.class, tormorginfos);
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
}
