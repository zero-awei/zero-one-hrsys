package com.zeroone.star.orgmanager.mapper;

import com.zeroone.star.orgmanager.entity.TOrmorgdz;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.j3.dto.orgmanager.OrgAddressDTO;
import com.zeroone.star.project.j3.query.OrgQuery;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

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

	/**
	 * @Title: selectOrgAddress
	 * @Description: 查询指定组织地址列表
	 * @Author: wh
	 * @DateTime: 2023/6/9 20:40
	 * @param orgQuery
	 * @return java.util.List<com.zeroone.star.project.j3.dto.orgmanager.OrgAddressDTO>
	 */
	public List<OrgAddressDTO> selectOrgAddress(OrgQuery orgQuery);
}
