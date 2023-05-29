package com.zeroone.star.common.mapper;

import com.zeroone.star.common.entity.TOrmpost;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 岗位集 Mapper 接口
 * </p>
 *
 * @author wh
 * @since 2023-05-29
 */
@Mapper
public interface TOrmpostMapper extends BaseMapper<TOrmpost> {

	/**
	 * @Title: selectOrmpostByOrgName
	 * @Description: 查询岗位名称
	 * @Author: wh
	 * @DateTime: 2023/5/29 23:44
	 * @param orgName
	 * @return java.util.List<java.lang.String>
	 */
	public List<TOrmpost> selectOrmpostByOrgName(String orgName);

}
