package com.zeroone.star.dashboard.mapper;

import com.zeroone.star.dashboard.entity.Srforg;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.dashboard.OrgDistributeDTO;
import com.zeroone.star.project.dto.dashboard.OrgEmployeeCountDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * Mapper 接口
 * </p>
 *
 * @author letian
 * @since 2023-05-21
 */
@Mapper
public interface SrforgMapper extends BaseMapper<Srforg> {
    /**
     * @param :
     * @return List<OrgDistributeDTO>
     * @author 乐天
     * @description:从t_srforg表中查询所有组织
     * @date 2023/5/22 8:13
     */
    @Select("select ORGNAME from t_srforg;")
    List<OrgDistributeDTO> selectAllOrg();


}
