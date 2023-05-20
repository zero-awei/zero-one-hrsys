package com.zeroone.star.project.dashboard;

import com.zeroone.star.project.dto.dashboard.OrgDistributeDTO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
  * @author：letian
  * @date  2023/5/20
  * @description：组织分布API
  * @version: 1.0
*/
public interface OrgDistributeApis {
    JsonVO<List<OrgDistributeDTO>> queryOrg();
}
