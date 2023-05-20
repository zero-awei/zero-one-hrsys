package com.zeroone.star.project.emplist;

import com.zeroone.star.project.dto.householdregistration_typestatuslist.HouseholdDregistrationTypestatusListDTO;

import com.zeroone.star.project.query.householdregistration_typestatuslist.HouseholdRegistrationTypestatuslistQuery;

import com.zeroone.star.project.vo.JsonVO;

/**
 * @author xiaoming xxx@163.com
 * @version 2023/5/19 23:43
 * @since JDK8
 */
public interface HouseholdRegistrationTypeStatusApi {

    /**
     *
     * @param query
     * @return
     */
    JsonVO<HouseholdDregistrationTypestatusListDTO> queryAll(HouseholdRegistrationTypestatuslistQuery query);
}
