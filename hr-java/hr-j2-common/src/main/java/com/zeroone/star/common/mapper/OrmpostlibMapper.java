package com.zeroone.star.common.mapper;

import com.zeroone.star.common.entity.Ormpostlib;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.common.GwTypeDTO;
import com.zeroone.star.project.dto.common.PostNatureDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * 岗位库 Mapper 接口
 * </p>
 *
 * @author letian
 * @since 2023-05-21
 */
@Mapper
public interface OrmpostlibMapper extends BaseMapper<Ormpostlib> {
    /**
     * @param :
     * @return List<GwTypeDTO>：岗位分类集合
     * @author 乐天
     * @description：根据相同的岗位类型进行两表联查得到岗位分类集合
     * @date 2023/5/22 8:52
     */
    @Select("select distinct b.PIMGWTYPENAME from t_ormpostlib a inner join t_pimgwtype b on a.GWTYPE = b.GWLX;")
    List<GwTypeDTO> selectGwtype();

    /**
     * @param :
     * @return List<PostNatureDTO>：岗位分类集合
     * @author 乐天
     * @description：两表联查得到岗位性质集合
     * @date 2023/5/22 11:36
     */
    @Select("select a.ORMPOSTLIBID, a.POSTNATURE from t_ormpostlib a inner join t_pimgwtype b on a.GWTYPE = b.GWLX group by a.GWTYPE;")
    List<PostNatureDTO> selectPostNature();
}
