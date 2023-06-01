package com.zeroone.star.orgmanager.service;

import com.zeroone.star.orgmanager.entity.TSrforg;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.j3.dto.orgmanager.OrgInfoDTO;

/**
 * <p>
 * 组织机构 服务类
 * </p>
 *
 * @author wh
 * @since 2023-05-31
 */
public interface ITSrforgService extends IService<TSrforg> {

	/**
	 * @Title: updateOrgInfo
	 * @Description: 修改组织机构信息
	 * @Author: wh
	 * @DateTime: 2023/5/31 20:32
	 * @param orgInfoDTO
	 * @return boolean
	 */
	public boolean updateOrgInfo(OrgInfoDTO orgInfoDTO);

}
