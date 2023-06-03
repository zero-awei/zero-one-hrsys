package com.zeroone.star.orgmanager.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.orgmanager.entity.TOrmduty;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Update;

import java.util.List;


/**
 * <p>
 * 职务管理 Mapper 接口
 * </p>
 *
 * @author loop
 * @since 2023-05-27
 */
@Mapper
public interface TOrmdutyMapper extends BaseMapper<TOrmduty> {

    @Update("update t_ormduty set UPDATEDATE = #{updatedate}, ORMDUTYNAME = #{ormdutyname}, " +
            "XH = #{xh}, FGLX = #{fglx} where ORMDUTYID = #{ormdutyid}")
    public boolean updateOrmdutyById(TOrmduty tOrmduty);

    public boolean deleteByOrmdutyids(List<String> ids);
}
