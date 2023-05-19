package com.zeroone.star.project.dept;

import com.zeroone.star.project.dto.dept.DeptDTO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;

/**
  * @author：letian
  * @date  2023/5/19
  * @description：删除部门信息API
  * @version: 1.0
*/
@Api(tags = "删除部门接口")
public interface RemoveDeptApis {
    /**
     * @param deptDTO: 查询条件
     * @return JsonVO<PageDTO<DeptDTO>> 删除结果
     * @author 乐天
     * @description 批量删除部门信息
     * @date 2023/5/19 10:36
     */
    @ApiOperation(value = "批量删除部门", notes = "根据多个部门ids删除部分部门")
    JsonVO<DeptDTO> removeDepts(DeptDTO deptDTO);

    /**
     * @param id: 部门编号
     * @return JsonVO<DeptDTO> 删除结果
     * @author 乐天
     * @description 根据部门编号删除指定部门信息
     * @date 2023/5/19 10:39
     */
    @ApiOperation(value = "删除部门", notes = "根据部门编号id删除指定部门")
    JsonVO<DeptDTO> removeDeptById(
            @ApiParam(value = "部门编号ID", required = true) String id);
}
