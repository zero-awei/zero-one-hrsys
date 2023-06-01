package com.zeroone.star.orgmanager.controller;

import com.zeroone.star.orgmanager.service.ITOrmorgdzService;
import com.zeroone.star.orgmanager.service.ITSrforgService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sample.SampleDTO;
import com.zeroone.star.project.j3.dto.DeleteDTO;
import com.zeroone.star.project.j3.dto.orgmanager.ModifyOrgAddressDTO;
import com.zeroone.star.project.j3.dto.orgmanager.OrgInfoDTO;
import com.zeroone.star.project.j3.dto.orgmager.OrgAddressDto;
import com.zeroone.star.project.j3.orgmanager.OrgInfoApis;
import com.zeroone.star.project.j3.query.OrgQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

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
    @Autowired
    ITSrforgService itSrforgService;
    @Autowired
    ITOrmorgdzService ormorgdzService;

    @DeleteMapping("remove-org-address")
    @ApiOperation("删除组织地址")
    @Override
    public JsonVO<Boolean> deleteDepAddress(@RequestBody OrgAddressDto orgAddressDto) {
        return null;
    }

    @PutMapping("modify-org-info")
    @ApiOperation("修改组织信息")
    @Override
    public JsonVO modifyOrgInfo(@ModelAttribute OrgInfoDTO orgInfoDTO) {
        boolean isSuccess = itSrforgService.updateOrgInfo(orgInfoDTO);
        if (isSuccess) {
            return JsonVO.success("修改成功");
        }else {
            return JsonVO.fail("修改失败");
        }
    }

    @PutMapping("modify-org-address")
    @ApiOperation("修改组织地址信息（导入的地址也通过这个接口更新）")
    @Override
    public JsonVO modifyOrgAddress(@RequestBody List<ModifyOrgAddressDTO> modifyOrgAddressDTOs) {
        //修改成功条数
        int successRow = ormorgdzService.updateOrgAddress(modifyOrgAddressDTOs);
        //需要修改的数据条数
        int size = modifyOrgAddressDTOs.size();
        int fail = size -successRow;
        if (fail == 0){
            return JsonVO.success("全部修改成功！");
        } else if (fail < size && fail >0) {
            return JsonVO.success("修改成功"+successRow+"条,"+fail+"条失败！");
        } else if (fail == size) {
            return JsonVO.fail("全部修改失败！");
        }
        return JsonVO.fail("修改失败");
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
    @ApiOperation("添加组织")
    @Override
    public JsonVO<Boolean> addOryData(@RequestBody OrgInfoDTO orgInfoDTO) {
        return JsonVO.success(true);
    }

    @Override
    public JsonVO<PageDTO<SampleDTO>> queryAllOrg(OrgQuery condition) {
        return null;
    }
}
