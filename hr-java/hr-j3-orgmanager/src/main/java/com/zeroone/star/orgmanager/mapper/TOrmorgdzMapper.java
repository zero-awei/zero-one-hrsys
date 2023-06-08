package com.zeroone.star.orgmanager.mapper;

import com.zeroone.star.orgmanager.entity.TOrmorgdz;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 * 组织地址维护 Mapper 接口
 * </p>
 *
 * @author wh
 * @since 2023-05-31
 */
@Mapper
public interface TOrmorgdzMapper extends BaseMapper<TOrmorgdz> {

	/**
	 * @Title: updateOrgAddress
	 * @Description: 修改组织地址信息
	 * @Author: wh
	 * @DateTime: 2023/6/1 16:34
	 * @param tOrmorgdz
	 * @return int
	 */
	public int updateOrgAddress(TOrmorgdz tOrmorgdz);
}
