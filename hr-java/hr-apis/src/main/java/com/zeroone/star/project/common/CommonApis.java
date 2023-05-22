package com.zeroone.star.project.common;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import com.zeroone.star.project.dto.common.StatusListDTO;
import com.zeroone.star.project.query.common.ZzmmQuery;
import com.zeroone.star.project.dto.common.GwTypeDTO;
import com.zeroone.star.project.dto.common.PostNatureDTO;
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


    /**
     * 描述：血型下拉列表
     *
     * @author C.C.
     * @version 1.0.0
     */
    JsonVO<List<DropdownListOptionDTO>> queryBloodType();

    /**
     * @param :
     * @return JsonVO<List < GwflDTO>> 部门分类信息
     * @author 乐天
     * @description 获取部门分类下拉列表
     * @date 2023/5/20 0:02
     */
    JsonVO<List<GwTypeDTO>> queryGwfl();

    /**
     * @param :
     * @return JsonVO<List < PostNatureDTO>> 部门性质信息
     * @author 乐天
     * @description 获取部门性质下拉列表
     * @date 2023/5/20 0:03
     */
    JsonVO<List<PostNatureDTO>> queryPostNature();
}
