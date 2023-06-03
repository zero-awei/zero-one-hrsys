package com.zeroone.star.orgmanager.service.impl;

import com.zeroone.star.orgmanager.entity.TOrmorgdz;
import com.zeroone.star.orgmanager.mapper.TOrmorgdzMapper;
import com.zeroone.star.orgmanager.service.ITOrmorgdzService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.j3.dto.orgmanager.ModifyOrgAddressDTO;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

/**
 * <p>
 * 组织地址维护 服务实现类
 * </p>
 *
 * @author wh
 * @since 2023-05-31
 */
@Service
public class TOrmorgdzServiceImpl extends ServiceImpl<TOrmorgdzMapper, TOrmorgdz> implements ITOrmorgdzService {

	@Autowired
	TOrmorgdzMapper mapper;

	/**
	 * @Title: updateOrgAddress
	 * @Description: 修改组织地址信息（导入的地址也通过这个接口更新）
	 * @Author: wh
	 * @DateTime: 2023/6/1 16:37
	 * @param modifyOrgAddressDTOs
	 * @return int
	 */
	@Transactional
	@Override
	public int updateOrgAddress(List<ModifyOrgAddressDTO> modifyOrgAddressDTOs) {
		//记录修改成功条数
		int row = 0;
		for (ModifyOrgAddressDTO dto : modifyOrgAddressDTOs) {
			TOrmorgdz tOrmorgdz = new TOrmorgdz();
			System.out.println(dto.toString());
			//将dto中的数据拷贝到tormorgdz对象中
			BeanUtils.copyProperties(dto,tOrmorgdz);
			int i = mapper.updateOrgAddress(tOrmorgdz);
			row += i;
		}
		return row;
	}
}
