package com.zeroone.star.project.j3.common;

import com.zeroone.star.project.vo.JsonVO;

import java.util.List;
import java.util.Map;

/**
 * ClassName: CommonApis
 * Description: 公共接口API定义
 *
 * @Author LR
 * @Create 2023/5/18 18:14
 * @Version 1.0
 */
public interface CommonApis {
    /**
     * 学习形式下拉列表
     * sql:SELECT * FROM `t_srfcodeitem` WHERE CODELISTID = 'FC4B9F96-E6E4-4170-9587-9DB970C57AA3'
     * @return Map<Integer,String> Integer: 代码标示符 String: 名称
     */
    JsonVO<Map<Integer,String>> LearningFormsDropdownList();

    /**
     * 学校性质下拉列表
     * sql:SELECT * FROM `t_srfcodeitem` WHERE CODELISTID = 'FDA27067-9E4F-4DC1-9676-2D65375359A9'
     * @return Map<Integer,String> Integer: 代码标示符 String: 名称
     */
    JsonVO<Map<Integer,String>> SchoolNatureDropdownList();
}
