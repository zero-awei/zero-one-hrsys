package com.zeroone.star.orgmanager.controller;

import com.zeroone.star.orm.OrmBmkqdzApi;
import com.zeroone.star.project.dto.orm.OrmBmkqdzDTO;
import com.zeroone.star.project.query.orm.OrmBmkqdzQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * @author mwx
 * @version 1.0
 * @description: TODO
 * @date 2023/5/18 15:54
 */
@RestController
@RequestMapping("org-manager")
@Api(tags = "组织管理")
public class OrmBmkqdzController implements OrmBmkqdzApi {

    @ApiOperation(value = "更新部门考勤地址")
    @PutMapping(value = "update-attendance-address")
    @Override
    public JsonVO<OrmBmkqdzDTO> modifyAttendanceAddress(OrmBmkqdzQuery query) {
        return null;
    }
}