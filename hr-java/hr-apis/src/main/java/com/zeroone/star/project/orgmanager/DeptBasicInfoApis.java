package com.zeroone.star.project.orgmanager;

import com.zeroone.star.project.dto.orgmanager.DepartmentDTO;
import com.zeroone.star.project.dto.orgmanager.KqdzDTO;
import com.zeroone.star.project.query.orgmanager.DeleteKqdzQuery;
import com.zeroone.star.project.query.orgmanager.DepartmentQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 * 描述：部门信息接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author C.C.
 * @version 1.0.0
 */
public interface DeptBasicInfoApis {
    /**
     * @Description: 查询指定部门基本信息
     * @params: [queryDeptBasicInfoByName]
     * @return: JsonVO<DepartmentDTO>
     * @Author: C.C.
     */
    JsonVO<DepartmentDTO> queryDeptBasicInfoByName(DepartmentQuery query);

    /**
     * @Description: 删除指定部门考勤地址信息
     * @params: [deleteKqdzByName]
     * @return: JsonVO<KqdzDTO>
     * @Author: C.C.
     */
    JsonVO<KqdzDTO> deleteKqdzByName(DeleteKqdzQuery query);
}
