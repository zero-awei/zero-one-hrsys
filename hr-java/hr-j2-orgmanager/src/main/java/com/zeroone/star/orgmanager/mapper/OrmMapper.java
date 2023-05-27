package com.zeroone.star.orgmanager.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.orgmanager.entity.Orgsector;
import com.zeroone.star.project.dto.orgmanager.ModifyDeptInfoDTO;
import com.zeroone.star.project.dto.orgmanager.DeptKqdzDTO;
import org.apache.ibatis.annotations.*;

import java.util.List;

/**
 * <p>
 * 组织信息 Mapper 接口
 * </p>
 *
 * @author rqs
 * @since 2023-05-19
 */
@Mapper
public interface OrmMapper extends BaseMapper<Orgsector> {
    @Select("SELECT * FROM t_orgsector WHERE orgsectorid = #{orgsectorid}")
    Orgsector selectById(@Param("orgsectorid") String orgsectorid);

    @Update("update t_orgsector set ordervalue = #{ordervalue}, orgsectorname = #{orgsectorname}, orgcode = #{orgcode}, shortname = #{shortname}, "
            + "bmlx = #{bmlx}, orgname = #{orgname}, belongregion = #{belongregion},qy=#{qy},bzkz=#{bzkz},bmbzrs=#{bmbzrs},startstopsign=#{startstopsign},belongou=#{belongou},updatedate = now() where orgsectorid = #{orgsectorid}")
    int updateDeptById(ModifyDeptInfoDTO modifyDeptInfoDTO);

    @Select("select ormbmkqdzname,attendancerange,updateman,updatedate from t_ormbmkqdz where ormorgsectorid = #{ormorgsectorid}")
    Page<DeptKqdzDTO> selectBmKqdzListById(Page<DeptKqdzDTO> page, @Param("ormorgsectorid") String ormorgsectorid);

}
