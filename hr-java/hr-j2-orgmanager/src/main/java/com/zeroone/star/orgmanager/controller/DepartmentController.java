package com.zeroone.star.orgmanager.controller;

import com.zeroone.star.orgmanager.service.ISrforgsectorService;
import com.zeroone.star.orgmanager.service.ITOrmbmkqdzService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.orgmanager.DepartmentDTO;
import com.zeroone.star.project.dto.orgmanager.ExportDTO;
import com.zeroone.star.project.dto.orm.OrmBmkqdzDTO;
import com.zeroone.star.project.orgmanager.DepartmentApis;
import com.zeroone.star.project.query.orgmanager.*;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：部门信息接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 浅墨
 * @version 1.0.0
 */
@RestController
@RequestMapping("org-manager")
@Api(tags = "部门信息")
public class DepartmentController implements DepartmentApis {
    @ApiOperation(value = "导出部门信息")
    @GetMapping("export-departments")
    @Override
    public JsonVO<ExportDTO> execExportDepartments(ExportDepartmentsQuery query) {
        return JsonVO.success(iSrforgsectorService.exportDepartments(query));
    }

    @ApiOperation(value = "导出指定部门考勤地址信息")
    @GetMapping("export-attendance-address")
    @Override
    public JsonVO<ExportDTO> execExportAttendanceAddress(ExportAttendanceAddressQuery query) {
        return JsonVO.success(ormbmkqdzService.exportAttendanceAddress(query));
    }

    @Resource
    ISrforgsectorService iSrforgsectorService;

    @GetMapping("org-list")
    @ApiOperation(value = "分页查询部门信息")
    @Override
    public JsonVO<PageDTO<DepartmentDTO>> queryAllDepartment(DepartmentQuery query) {
        return JsonVO.success(iSrforgsectorService.listAllDepartment(query));
    }

    @Resource
    private ITOrmbmkqdzService ormbmkqdzService;

    @ApiOperation(value = "更新部门考勤地址")
    @PutMapping(value = "update-attendance-address")
    @Override
    public JsonVO<String> modifyAttendanceAddress(OrmBmkqdzDTO ormBmkqdzDTO) {
        return ormbmkqdzService.updateAttendanceAddress(ormBmkqdzDTO);
    }

    @ApiOperation(value = "查询指定部门基本信息")
    @GetMapping(value = "query-dept-info-by-id")
    @Override
    public JsonVO<DepartmentDTO> queryDeptBasicInfoById(DeptInfoQuery query) {
        return JsonVO.success(iSrforgsectorService.queryDeptById(query));
    }

    @ApiOperation(value = "删除指定部门考勤地址信息")
    @DeleteMapping(value = "delete-attendance-address-by-id")
    @Override
    public JsonVO<Boolean> deleteKqdzById(DeleteKqdzQuery query) {
        return JsonVO.success(ormbmkqdzService.removeById(query.getKqdzId()));
    }
}
