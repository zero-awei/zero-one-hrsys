package com.zeroone.star.project.orgmanager;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.orgmanager.DepartmentDTO;
import com.zeroone.star.project.dto.orgmanager.ExportDTO;
import com.zeroone.star.project.dto.orgmanager.KqdzDTO;
import com.zeroone.star.project.dto.orm.OrmBmkqdzDTO;
import com.zeroone.star.project.query.orgmanager.*;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 * 描述：部门信息接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 浅墨
 * @version 1.0.0
 */
public interface DepartmentApis {
    /**
     * 导出部门信息
     *
     * @return 导出文件下载地址
     */
    JsonVO<ExportDTO> execExportDepartments(ExportDepartmentsQuery query);

    /**
     * 导出指定部门考勤地址信息
     *
     * @return 导出文件下载地址
     */
    JsonVO<ExportDTO> execExportAttendanceAddress(ExportAttendanceAddressQuery query);

    /**
     * 分页查询部门信息
     *
     * @param query
     * @return
     */
    JsonVO<PageDTO<DepartmentDTO>> queryAllDepartment(DepartmentQuery query);


    JsonVO<String> modifyAttendanceAddress(OrmBmkqdzDTO ormBmkqdzDTO);


    /**
     * @Description: 查询指定部门基本信息
     * @params: [queryDeptBasicInfoByName]
     * @return: JsonVO<DepartmentDTO>
     * @Author: C.C.
     */
    JsonVO<DepartmentDTO> queryDeptBasicInfoById(DeptInfoQuery query);

    /**
     * @Description: 删除指定部门考勤地址信息
     * @params: [deleteKqdzByName]
     * @return: JsonVO<KqdzDTO>
     * @Author: C.C.
     */
    JsonVO<Boolean> deleteKqdzById(DeleteKqdzQuery query);
}
