package com.zeroone.star.orgmanager.service.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.orgmanager.entity.TOrmorgdz;
import com.zeroone.star.orgmanager.mapper.TOrmorgdzMapper;
import com.zeroone.star.orgmanager.service.ITOrmorgdzService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j3.dto.orgmager.OrgAddressDto;
import com.zeroone.star.project.j3.dto.orgmanager.ExportOrgAddressDto;
import com.zeroone.star.project.j3.dto.orgmanager.JobTitleDTO;
import com.zeroone.star.project.j3.dto.orgmanager.ModifyOrgAddressDTO;
import com.zeroone.star.project.j3.dto.orgmanager.OrgAddressDTO;
import com.zeroone.star.project.j3.query.OrgQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.util.Collections;
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

	@Resource
	EasyExcelComponent component;

	@Resource
	private FastDfsClientComponent fastDfsClientComponent;

	@Override
	public boolean deleteOrgAddress(OrgAddressDto orgAddressDto) {
		int flag = baseMapper.deleteBatchIds(orgAddressDto.getIds());
		if (flag!=0){
			return true;
		}
		return false;
	}

	@Override
	public ExportOrgAddressDto exportOrgAddress(OrgAddressDto orgAddressDto) throws Exception{
		//查询数据
		List<TOrmorgdz> tOrmorgdzs = baseMapper.selectBatchIds(orgAddressDto.getIds());
		// 创建输出流
		ByteArrayOutputStream out = new ByteArrayOutputStream();
		// 导出数据到输出流
		component.export("测试", out, TOrmorgdz.class, tOrmorgdzs);
		//上传FastDfs
		FastDfsFileInfo fastDfsFileInfo = fastDfsClientComponent.uploadFile(out.toByteArray(), "xlsx");

		//验证
		if (fastDfsFileInfo == null) {
			return null;
		}

		// 返回下载地址
		ExportOrgAddressDto exportOrgAddressDto =new ExportOrgAddressDto();
		exportOrgAddressDto.setUrl(fastDfsClientComponent.fetchUrl(fastDfsFileInfo, "http://", true));

		return exportOrgAddressDto;
	}

	/**
	 * @Title: listOrgAddress
	 * @Description: 分页查询指定组织地址列表
	 * @Author: wh
	 * @DateTime: 2023/6/9 20:49
	 * @param query
	 * @return com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.dto.PageDTO<com.zeroone.star.project.j3.dto.orgmanager.OrgAddressDTO>>
	 */
	@Override
	public JsonVO<PageDTO<OrgAddressDTO>> listOrgAddress(OrgQuery query) {
		Page<OrgAddressDTO> page = new Page<>(query.getPageIndex(), query.getPageSize());
		List<OrgAddressDTO> orgAddressDTOS = mapper.selectOrgAddress(query);

		// 将查询结果封装为Page对象
		page.setRecords(orgAddressDTOS);
		page.setTotal(orgAddressDTOS.size());
		return JsonVO.create(PageDTO.create(page, OrgAddressDTO.class), ResultStatus.SUCCESS);
	}
}
