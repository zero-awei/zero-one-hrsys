package com.zeroone.star.project.dashboard;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.dashboard.PimVocationalListDTO;
import com.zeroone.star.project.query.dashboard.PimVocationalListQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * @author mwx
 * @version 1.0
 * @description: TODO
 * @date 2023/5/18 12:01
 */
public interface PimVocationalListApi {

    /**
     * 查询所有员工职业资格证书
     * @param query
     * @return
     */
    JsonVO<List<PimVocationalListDTO>> queryPimVocational(PimVocationalListQuery query);


}
