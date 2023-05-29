package com.zeroone.star.orgmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.orgmanager.entity.Ormbmkqdz;
import com.zeroone.star.project.dto.orm.OrmBmkqdzDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.orgmanager.entity.TOrmbmkqdz;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 * 部门地址维护 服务类
 * </p>
 *
 * @author wxs
 * @since 2023-05-19
 */
public interface ITOrmbmkqdzService extends IService<TOrmbmkqdz> {
 * @author mwx
 * @since 2023-05-24
 */
public interface ITOrmbmkqdzService extends IService<Ormbmkqdz> {
    /**
     * 更改部门考勤地址
     * @param ormBmkqdzDTO
     * @return
     */
    JsonVO<String> updateAttendanceAddress(OrmBmkqdzDTO ormBmkqdzDTO);


}
