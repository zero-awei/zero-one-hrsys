package com.zeroone.star.common.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.organizational_propertystatuslist.Organizational_propertyStatusListDTO;
import com.zeroone.star.project.dto.owning_regionstatuslist.Owning_regionStatusListDTO;
import com.zeroone.star.project.emplist.Organizational_propertyStatusApi;
import com.zeroone.star.project.emplist.Owning_regionStatusApi;
import com.zeroone.star.project.query.organizational_propertystatuslist.Organizational_propertyStatusListQuery;
import com.zeroone.star.project.query.owning_regionstatuslist.Owning_regionStatusListQuery;
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
public class Owning_regionStatusListController implements Owning_regionStatusApi {
    @RequestMapping("Owning_region-status")
    @ApiOperation(value = "所属区域下拉列表")

    @Override
    public JsonVO<PageDTO<Owning_regionStatusListDTO>> queryAll(Owning_regionStatusListQuery query) {
        return null;
    }
}
