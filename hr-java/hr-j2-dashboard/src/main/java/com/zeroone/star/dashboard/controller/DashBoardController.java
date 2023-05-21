package com.zeroone.star.dashboard.controller;

import com.zeroone.star.dashboard.service.ISrforgService;
import com.zeroone.star.project.dashboard.OrgDistributeApis;
import com.zeroone.star.project.dto.dashboard.OrgDistributeDTO;
import com.zeroone.star.project.dto.dashboard.OrgEmployeeCountDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.List;

/**
  * @author：letian
  * @date  2023/5/20
  * @description：组织分布接口
  * @version: 1.0
*/
@RestController
@RequestMapping("/dash-board")
@Api(tags = "组织分布接口")
public class DashBoardController implements OrgDistributeApis {
    @Resource
    private ISrforgService srforgService;

    @ApiOperation(value = "获取组织分布信息")
    @GetMapping("/query-org-distribute")
    @Override
    public JsonVO<List<OrgDistributeDTO>> queryOrgDistribute() {
        List<OrgDistributeDTO> list = srforgService.getAllOrg();
        return JsonVO.success(list);
    }

    @ApiOperation(value = "获取组织人数信息")
    @GetMapping("/query-org-count")
    @Override
    public JsonVO<OrgEmployeeCountDTO> queryEmployeeCount() {
        List<OrgEmployeeCountDTO> list = srforgService.getOrgCount();
        return null;
    }
}
