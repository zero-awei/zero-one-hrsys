package com.zeroone.star.project.common;

import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * <p>
 * 描述：公用接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 浅墨
 * @version 1.0.0
 */
public interface CommonApis {

    /**
     * 获取编制控制下拉列表
     *
     * @return 查询结果
     */
    JsonVO<List<DropdownListOptionDTO>> queryStaffingControl();
}
