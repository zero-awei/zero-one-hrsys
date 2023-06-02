package com.zeroone.star.orgmanager.service.impl;


import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.orgmanager.entity.Ormbmkqdz;
import com.zeroone.star.orgmanager.mapper.TOrmbmkqdzMapper;
import com.zeroone.star.orgmanager.service.ITOrmbmkqdzService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.dto.orgmanager.DeptKqdzDTO;
import com.zeroone.star.project.dto.orgmanager.ExportDTO;
import com.zeroone.star.project.dto.orm.OrmBmkqdzDTO;
import com.zeroone.star.project.query.orgmanager.ExportAttendanceAddressQuery;
import com.zeroone.star.project.vo.JsonVO;
import lombok.SneakyThrows;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.time.LocalDateTime;
import java.util.List;

@Mapper(componentModel = "spring")
interface MsOrmbmkqdzMapper {
    List<DeptKqdzDTO> dosToDTOS(List<Ormbmkqdz> ormbmkqdzs);
}

/**
 * <p>
 * 部门地址维护 服务实现类
 * </p>
 *
 * @author mwx
 * @since 2023-05-24
 */
@Service
public class TOrmbmkqdzServiceImpl extends ServiceImpl<TOrmbmkqdzMapper, Ormbmkqdz> implements ITOrmbmkqdzService {

    @Resource
    private TOrmbmkqdzMapper tOrmbmkqdzMapper;

    @Override
    public JsonVO<String> updateAttendanceAddress(OrmBmkqdzDTO ormBmkqdzDTO) {
        Ormbmkqdz ormbmkqdz = baseMapper.selectById(ormBmkqdzDTO.getDepartmentId());
        if (ormbmkqdz == null) {
            return JsonVO.success("该地址不存在");
        }
        //设置更新时间
        ormBmkqdzDTO.setUpdatedate(LocalDateTime.now());
        System.out.println(ormBmkqdzDTO);
        int res = tOrmbmkqdzMapper.updateAttendanceAddress(ormBmkqdzDTO);
        return JsonVO.success("更新成功");
        //return res == 1 ? JsonVO.success("更新成功"):JsonVO.fail("更新失败");
    }

    @Resource
    private MsOrmbmkqdzMapper msOrmbmkqdzMapper;

    @Resource
    private EasyExcelComponent component;

    @Resource
    private FastDfsClientComponent fastDfsClientComponent;

    @SneakyThrows
    @Override
    public ExportDTO exportAttendanceAddress(ExportAttendanceAddressQuery query) {
        LambdaQueryWrapper<Ormbmkqdz> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(Ormbmkqdz::getOrmorgsectorid, query.getDepartmentId());
        List<DeptKqdzDTO> deptkqdzs = msOrmbmkqdzMapper.dosToDTOS(baseMapper.selectList(wrapper));
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        component.export("测试", out, DeptKqdzDTO.class, deptkqdzs);
        FastDfsFileInfo info = fastDfsClientComponent.uploadFile(out.toByteArray(), "xlsx");
        if (info == null) {
            return null;
        }
        ExportDTO exportDTO = new ExportDTO();
        exportDTO.setUrl(fastDfsClientComponent.fetchUrl(info, "http://", true));
        return exportDTO;
    }


}
