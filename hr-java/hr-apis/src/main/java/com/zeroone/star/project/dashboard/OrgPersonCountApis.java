package com.zeroone.star.project.dashboard;


import com.zeroone.star.project.dto.dashboard.OrgPersonCountDTO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
  * @author：letian
  * @date  2023/6/2
  * @description： 组织人数API
  * @version: 1.0
*/
public interface OrgPersonCountApis {
    /**
     * @param :
     * @return JsonVO<List<OrgPersonCountDTO>>
     * @author 乐天
     * @description 获取组织人数信息
     * @date 2023/6/2 20:41
     */
    JsonVO<List<OrgPersonCountDTO>> queryOrgPersonCount();

}
