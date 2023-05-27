package com.zeroone.star.orgmanager.controller;

import com.zeroone.star.orgmanager.service.ITOrmorginfoService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sample.SampleDTO;
import com.zeroone.star.project.j3.dto.AddOrgInfoDTO;
import com.zeroone.star.project.j3.dto.DeleteDTO;
import com.zeroone.star.project.j3.dto.orgmager.OrgAddressDto;
import com.zeroone.star.project.j3.dto.orgmanager.ModifyOrgAddressDTO;
import com.zeroone.star.project.j3.dto.orgmanager.OrgInfoDTO;
import com.zeroone.star.project.j3.orgmanager.OrgInfoApis;
import com.zeroone.star.project.j3.query.OrgQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
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

    @Resource
    ITOrmorginfoService itOrmorginfoService;

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

    @PostMapping("add-org-info")
    @ApiOperation("添加组织")
    @Override
    public JsonVO<String> addOryData(@RequestBody AddOrgInfoDTO addOrgInfoDTO){
        try {
            itOrmorginfoService.saveOryData(addOrgInfoDTO);
            return JsonVO.success("添加成功");
        }catch (Exception e){
            return JsonVO.fail("添加失败");
        }

    }


    @Override
    public JsonVO<PageDTO<SampleDTO>> queryAllOrg(OrgQuery condition) {
        return null;
    }
}
