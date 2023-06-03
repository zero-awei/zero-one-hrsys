package com.zeroone.star.orgmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.zeroone.star.orgmanager.entity.TSrforg;
import com.zeroone.star.orgmanager.mapper.TSrforgMapper;
import com.zeroone.star.orgmanager.service.ITSrforgService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.j3.dto.orgmanager.OrgInfoDTO;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.orgmanager.entity.TSrforg;
import com.zeroone.star.orgmanager.mapper.TSrforgMapper;
import com.zeroone.star.orgmanager.service.ITSrforgService;
import com.zeroone.star.project.j3.dto.AddOrgInfoDTO;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
/**
 * <p>
 * 描述：TSrforg对应MpStruct映射接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Mapper(componentModel = "spring")
interface MsTSrforgMapper {
    /**
     * AddOrgInfoDTO 转换 TSrforg dao
     * @param addOrgInfoDTO dto对象
     * @return do对象
     */
    TSrforg AddOrgInfoDTOToTSrforg(AddOrgInfoDTO addOrgInfoDTO);
}
/**
 * <p>
 * 组织机构 服务实现类
 * </p>
 *
 * @author wh
 * @since 2023-05-31
 */
@Service
public class TSrforgServiceImpl extends ServiceImpl<TSrforgMapper, TSrforg> implements ITSrforgService {

	@Autowired
	TSrforgMapper mapper;

	/**
	 * @Title: updateOrgInfo
	 * @Description: 修改机构信息
	 * @Author: wh
	 * @DateTime: 2023/5/31 20:35
	 * @param orgInfoDTO
	 * @return boolean
	 */
	@Transactional
	@Override
	public boolean updateOrgInfo(OrgInfoDTO orgInfoDTO) {
		//得到上级组织名称
		String porgname = orgInfoDTO.getPorgname();
		//查询该组织对应的orgid
		QueryWrapper<TSrforg> wrapper = new QueryWrapper<>();
		wrapper.select("ORGID")
				.eq("ORGNAME",porgname);
		TSrforg tSrforg = mapper.selectOne(wrapper);
		//将父级id设置到orgInfoDTO中
		orgInfoDTO.setPorgid(tSrforg.getOrgid());
		System.out.println(orgInfoDTO.toString());
		//将orgInfoDTO的值拷贝到TSrforg对象中
		BeanUtils.copyProperties(orgInfoDTO, tSrforg, "ORGID");
		//修改数据
		int row = mapper.updateOrgInfo(tSrforg);
		return row > 0 ? true:false;
	}
	@Resource
	MsTSrforgMapper msTSrforgMapper;

	@Override
	public void saveOryData(AddOrgInfoDTO addOrgInfoDTO) {
		//将DTO转为DAO传入
		baseMapper.insert(msTSrforgMapper.AddOrgInfoDTOToTSrforg(addOrgInfoDTO));
	}
}


