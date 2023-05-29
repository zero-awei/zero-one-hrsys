package com.zeroone.star.orgmanager.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.orgmanager.entity.Ormbmkqdz;
import com.zeroone.star.project.dto.orm.OrmBmkqdzDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

/**
 * <p>
 * 部门地址维护 Mapper 接口
 * </p>
 *
 * @author mwx
 * @since 2023-05-24
 */
@Mapper
public interface TOrmbmkqdzMapper extends BaseMapper<Ormbmkqdz> {

    int updateAttendanceAddress(@Param("OrmBmkqdzDTO") OrmBmkqdzDTO ormBmkqdzDTO);


}
