package com.zeroone.star.common.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.organizational_propertystatuslist.Organizational_propertyStatusListDTO;
import com.zeroone.star.project.emplist.Organizational_propertyStatusApi;
import com.zeroone.star.project.query.organizational_propertystatuslist.Organizational_propertyStatusListQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * @author abner
 * @version 1.0
 */

@RestController
@RequestMapping("employee")
public class Organizational_propertyStatusListController implements Organizational_propertyStatusApi {

    @RequestMapping("Organizational_property-status")
    @ApiOperation(value ="组织性质下拉列表")

    @Override
    public JsonVO<PageDTO<Organizational_propertyStatusListDTO>> queryAll(Organizational_propertyStatusListQuery query) {
        return null;
    }
}
