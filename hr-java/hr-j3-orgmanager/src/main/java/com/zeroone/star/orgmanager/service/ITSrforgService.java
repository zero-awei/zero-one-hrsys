package com.zeroone.star.orgmanager.service;

import com.zeroone.star.orgmanager.entity.TSrforg;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.j3.dto.AddOrgInfoDTO;
import com.zeroone.star.project.j3.dto.orgmanager.OrgInfoDTO;
import com.zeroone.star.project.j3.dto.orgmanager.OrgInfoDTO;

/**
 * <p>
 * 组织机构 服务类
 * </p>
 *
 * @author lr
 * @since 2023-05-29
 */
public interface ITSrforgService extends IService<TSrforg> {

    /**
     * 添加组织信息
     * @param addOrgInfoDTO 添加组织信息类
     */
    void saveOryData(AddOrgInfoDTO addOrgInfoDTO);
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
