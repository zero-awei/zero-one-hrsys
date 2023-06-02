package com.zeroone.star.orgmanager.service.impl;

import com.zeroone.star.orgmanager.entity.TOrmorgdz;
import com.zeroone.star.orgmanager.mapper.TOrmorgdzMapper;
import com.zeroone.star.orgmanager.service.ITOrmorgdzService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.j3.dto.orgmanager.ExportOrgAddressDto;
import com.zeroone.star.project.j3.dto.orgmanager.OrgAddressDto;
import org.springframework.stereotype.Service;
import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.util.List;

/**
 * <p>
 * 组织地址维护 服务实现类
 * </p>
 *
 * @author wutong
 * @since 2023-05-30
 */
@Service
public class TOrmorgdzServiceImpl extends ServiceImpl<TOrmorgdzMapper, TOrmorgdz> implements ITOrmorgdzService {

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
}
