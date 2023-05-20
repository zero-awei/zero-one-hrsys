package com.zeroone.star.project.common;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import com.zeroone.star.project.dto.common.StatusListDTO;
import com.zeroone.star.project.query.common.ZzmmQuery;
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

    /**
     * 获取证件类型下拉列表
     *
     * @return 查询结果
     */
    JsonVO<List<DropdownListOptionDTO>> queryCertificateType();

    /**
     * 查询员工状态信息
     *
     * @return
     */
    JsonVO<PageDTO<StatusListDTO>> queryEmployeeStatus();

    /**
     * 查询部门类型信息
     *
     * @return
     */
    JsonVO<List<DropdownListOptionDTO>> queryDTStatus();

    /**
     * 查询组织性质信息
     *
     * @return
     */
    JsonVO<List<DropdownListOptionDTO>> queryOPStatus();

    /**
     * 所属区域性质信息
     *
     * @return
     */
    JsonVO<List<DropdownListOptionDTO>> queryORStatus();

    /**
     * 补贴标准性质信息
     *
     * @return
     */
    JsonVO<List<DropdownListOptionDTO>> querySSStatus();

    /**
     * @Description: 获取政治面貌下拉列表
     * @params: []
     * @return: JsonVO<ZzmmQuery>
     * @Author: Rqs
     * @Date: 2023/5/19 23:17
     */
    JsonVO<ZzmmQuery> queryZzmm();
}
