package com.zeroone.star.project.dashboard;

import com.zeroone.star.project.dto.dashboard.AgeDTO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * <p>
 * 描述：系统首页接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author C.C.
 * @version 1.0.0
 */
public interface AgeDistributeApis {
    JsonVO<List<AgeDTO>> queryAgeDistribute();
}
