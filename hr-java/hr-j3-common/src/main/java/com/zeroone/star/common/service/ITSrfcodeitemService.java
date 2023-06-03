package com.zeroone.star.common.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.common.entity.TSrfcodeitem;
import com.zeroone.star.project.j3.dto.DropdownListDTO;
import com.zeroone.star.common.entity.TSrfcodeitem;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.j3.dto.DropdownListOptionDTO;
import com.zeroone.star.project.j3.query.common.DisciplineTypeQuery;
import com.zeroone.star.project.j3.query.common.EducationTypeQuery;

import java.util.List;

/**
 * <p>
 * 代码项 服务类
 * </p>
 *
 * @author breezelr
 * @since 2023-05-27
 */
public interface ITSrfcodeitemService extends IService<TSrfcodeitem> {

    /**
     * 学校性质下拉菜单
     * sql:SELECT * FROM `t_srfcodeitem` WHERE CODELISTID = 'FDA27067-9E4F-4DC1-9676-2D65375359A9'
     *
     * @return 查询结果
     */
    List<DropdownListDTO> listSchoolNature();

    /**
     * 学习形式下拉菜单
     * sql: SELECT * FROM `t_srfcodeitem` WHERE CODELISTID = 'FC4B9F96-E6E4-4170-9587-9DB970C57AA3'
     *
     * @return 查询结果
     */
    List<DropdownListDTO> listLearningForms();
    List<DropdownListOptionDTO> listDistributionStatus(String codeitem);

    public List<String> listEducationType(EducationTypeQuery education);

    public List<String> listDisciplineType(DisciplineTypeQuery discipline);

}
