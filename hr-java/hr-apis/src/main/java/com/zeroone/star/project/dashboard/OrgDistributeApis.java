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
    /**
     * @param :
     * @return JsonVO<List<OrgDistributeDTO>>
     * @author 乐天
     * @description 获取组织分布信息
     * @date 2023/5/20 17:52
     */
    JsonVO<List<OrgDistributeDTO>> queryOrgDistribute();

}
