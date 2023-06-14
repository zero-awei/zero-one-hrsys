package com.zeroone.star.project.j3.common;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j3.dto.DropdownListDTO;
import com.zeroone.star.project.j3.dto.DropdownListOptionDTO;
import com.zeroone.star.project.j3.dto.languageability.LanguageAbilityDTO;
import com.zeroone.star.project.j3.query.common.*;
import com.zeroone.star.project.j3.query.languageability.LanguageAbilityQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;


/**
 * <p>
 * 描述：公共接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 梧桐
 * @version 1.0.0
 */
public interface CommonApis {

    /**
     * 获取分配信息中的职务名称下拉列表数据
     *
     * @param
     * @return 查询结果
     */
    JsonVO<List<DropdownListOptionDTO>> queryPositionTitle(PositionTitleDropdownListQuery query);

    /**
     * 获取分配信息中的岗位名称下拉列表数据
     *
     * @param
     * @return 查询结果
     */
    JsonVO<List<DropdownListOptionDTO>> queryJobTitle(JobTitleDropdownListQuery query);

    /**
     * @return {@link JsonVO< List< DropdownListOptionDTO>>}
     * @Author H_lzu
     * @Date 20:27 2023/5/19
     */
    JsonVO<List<DropdownListOptionDTO>> queryRewardPenaltyLevels();

    /**
     * 军转类型下拉列表
     *
     * @return
     * @return {@link JsonVO< List< DropdownListOptionDTO>>}
     * @Author H_lzu
     * @Date 20:24 2023/5/19
     */
    JsonVO<List<DropdownListOptionDTO>> queryTypeofMilitaryTransfer();

    /**
     * 分配形式下拉列表
     *
     * @return {@link JsonVO< List< DropdownListOptionDTO>>}
     * @Author H_lzu
     * @Date 20:01 2023/6/4
     */
    JsonVO<List<DropdownListOptionDTO>> queryDistributionForm();

    /**
     * 分配状态下拉列表
     *
     * @return {@link JsonVO< List< DropdownListOptionDTO>>}
     * @Author H_lzu
     * @Date 20:47 2023/5/19
     */
    JsonVO<List<DropdownListOptionDTO>> queryDistributionStatus();

    /**
     * 组织形式下拉列表
     *
     * @return {@link JsonVO< List< DropdownListOptionDTO>>}
     * @Author H_lzu
     * @Date 20:49 2023/5/19
     */
    JsonVO<List<DropdownListOptionDTO>> queryNameofAssociation();

    /**
     * 部门名称下拉列表
     * 库： t_orgSector
     *
     * @param sectorNameQuery 组织id和部门关键字
     * @return 查询对象
     */
    JsonVO<List<DropdownListDTO>> querySectorName(SectorNameQuery sectorNameQuery);

    /**
     * 学习形式下拉列表
     *
     * @return 学习形式List
     */
    JsonVO<List<DropdownListDTO>> queryLearningForms();

    /**
     * 学科类型下拉列表
     *
     * @param discipline
     * @return 集合
     */
    JsonVO<List<String>> listDisciplineType(DisciplineTypeQuery discipline);

    /**
     * 学校性质下拉列表
     *
     * @return 学校性质List
     */
    JsonVO<List<DropdownListDTO>> querySchoolNature();

    /**
     * 分页查询某人的语言能力
     */
//    JsonVO<PageDTO<List<LanguageAbilityDTO>>> queryLanguageAbilityList(LanguageAbilityQuery personId);


    /**
     * 学历类型下拉列表
     *
     * @param  education
     * @return 集合
     */
    JsonVO<List<String>> listEducationType(EducationTypeQuery education);

    /**
     * 获取与本人关系
     *
     * @return 数据对象
     * @Date 21:27 2023/5/19
     */
    JsonVO<List<String>> queryRelationship();

    /**
     * 入职渠道下拉列表
     *
     * @return {@link JsonVO< List< DropdownListOptionDTO>>}
     * @Author H_lzu
     * @Date 17:27 2023/5/24
     */
    JsonVO<List<DropdownListOptionDTO>> queryEntryChannel();

    /**
     * 分配方式下拉列表
     *
     * @return {@link JsonVO< List< DropdownListOptionDTO>>}
     * @Author H_lzu
     * @Date 17:28 2023/5/24
     */
    JsonVO<List<DropdownListOptionDTO>> queryAllocation();

    /**
     * 语种类型下拉列表
     *
     * @return {@link JsonVO< List< String>>}
     * @Author H_lzu
     * @Date 22:09 2023/5/24
     * @Date 2023/5/29 /loop
     */
    JsonVO<List<String>> queryLanguageType();

    /**
     * 外语等级下拉列表
     *
     * @return
     */
    public JsonVO<List<String>> queryLanguageLevel();



    /**
     * 组织名称下拉菜单
     * @param
     * @return
     */
    public JsonVO<List<String>> queryOrganizationName(String id);
}
