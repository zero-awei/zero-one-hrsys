package com.zeroone.star.common.mapper;

import com.zeroone.star.common.entity.TSrforg;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * 组织机构 Mapper 接口
 * </p>
 *
 * @author tomcatcc
 * @since 2023-06-09
 */
@Mapper
public interface TSrforgMapper extends BaseMapper<TSrforg> {
    	/**
    		 *获取组织名称
    		 * @param id
    		 * @return List
    		 */
        @Select("select ORGNAME from t_srforg where PORGID = #{id}")
        public List<String> queryOrganizationName(String id);
}
