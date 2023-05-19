package com.zeroone.star.project.emplist;

import com.zeroone.star.project.dto.householdregistration_typestatuslist.HouseholdDregistration_typestatusListDTO;
import com.zeroone.star.project.query.householdregistration_typestatuslist.HouseholdRegistration_TypestatuslistQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * @author xiaoming xxx@163.com
 * @version 2023/5/19 23:43
 * @since JDK8
 */
public interface HouseholdRegistration_TypeStatusApi {

    /**
     *
     * @param query
     * @return
     */
    JsonVO<HouseholdDregistration_typestatusListDTO> queryAll(HouseholdRegistration_TypestatuslistQuery query);
}
