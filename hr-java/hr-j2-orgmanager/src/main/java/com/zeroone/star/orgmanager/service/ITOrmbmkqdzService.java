package com.zeroone.star.orgmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.orgmanager.entity.Ormbmkqdz;
import com.zeroone.star.project.dto.orgmanager.ExportDTO;
import com.zeroone.star.project.dto.orm.OrmBmkqdzDTO;
import com.zeroone.star.project.query.orgmanager.ExportAttendanceAddressQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 * 部门地址维护 服务类
 * </p>
 *
 * @author mwx
 * @since 2023-05-24
 */
public interface ITOrmbmkqdzService extends IService<Ormbmkqdz> {
    /**
     * 更改部门考勤地址
     *
     * @param ormBmkqdzDTO
     * @return
     */
    JsonVO<String> updateAttendanceAddress(OrmBmkqdzDTO ormBmkqdzDTO);


    ExportDTO exportAttendanceAddress(ExportAttendanceAddressQuery query);
}
