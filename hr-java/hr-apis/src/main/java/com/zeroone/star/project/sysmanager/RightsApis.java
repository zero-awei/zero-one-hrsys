package com.zeroone.star.project.sysmanager;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.RightsDTO;
import com.zeroone.star.project.query.sysmanager.RightsQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 * 描述：权限管理API接口定义
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author
 * @version 1.0.0
 */

public interface RightsApis {
    /**
     * 分页查询列表
     * @param query 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<RightsDTO>> queryAll(RightsQuery query);

}
