package com.zeroone.star.orm;


import com.zeroone.star.project.dto.orm.OrmBmkqdzDTO;
import com.zeroone.star.project.query.orm.OrmBmkqdzQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * @author mwx
 * @version 1.0
 * @description: TODO
 * @date 2023/5/19 23:01
 */
public interface OrmBmkqdzApi {
    /**
     * 更改部门考勤地址
     * @param query
     * @return
     */
    JsonVO<OrmBmkqdzDTO> modifyAttendanceAddress(OrmBmkqdzQuery query);

}
