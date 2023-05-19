package com.zeroone.star.project.j3.common;

import com.zeroone.star.project.j3.query.common.DisciplineTypeQuery;
import com.zeroone.star.project.j3.query.common.EducationTypeQuery;
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
     * 学科类型下拉列表
     * @param disciplineTypeQuery
     * @return 集合
     */
    JsonVO<List<String>> listDisciplineType(DisciplineTypeQuery disciplineTypeQuery);

    /**
     * 学历类型下拉列表
     * @param educationTypeQuery
     * @return 集合
     */
    JsonVO<List<String>> listEducationType(EducationTypeQuery educationTypeQuery);
}
