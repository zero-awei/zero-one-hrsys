package com.zeroone.star.orgmanager.mapper;

import com.zeroone.star.orgmanager.entity.TSrforg;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 * 组织机构 Mapper 接口
 * </p>
 *
 * @author wh
 * @since 2023-05-31
 */
@Mapper
public interface TSrforgMapper extends BaseMapper<TSrforg> {

	/**
	 * @Title: updateOrgInfo
	 * @Description: 修改组织机构信息
	 * @Author: wh
	 * @DateTime: 2023/5/31 20:32
	 * @param srforg
	 * @return boolean
	 */
	public int updateOrgInfo(TSrforg srforg);

}
