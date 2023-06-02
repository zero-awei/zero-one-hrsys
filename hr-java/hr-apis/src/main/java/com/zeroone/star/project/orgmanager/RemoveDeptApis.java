package com.zeroone.star.project.orgmanager;

import com.zeroone.star.project.dto.orgmanager.DeptDTO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;

/**
  * @author：letian
  * @date  2023/5/19
  * @description：删除部门信息API
  * @version: 1.0
*/
public interface RemoveDeptApis {
    /**
     * @param deptDTO: 查询条件
     * @return JsonVO<PageDTO<DeptDTO>> 删除结果
     * @author 乐天
     * @description 批量删除部门信息
     * @date 2023/5/19 10:36
     */
    @ApiOperation(value = "批量删除部门", notes = "根据多个部门ids删除部分部门")
    JsonVO<String> removeDeptByIds(DeptDTO deptDTO);

}
