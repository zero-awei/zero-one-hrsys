package com.zeroone.star.orgmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.orgmanager.entity.Srforgsector;
import com.zeroone.star.orgmanager.mapper.SrforgsectorMapper;
import com.zeroone.star.orgmanager.service.ISrforgsectorService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.orgmanager.DepartmentDTO;
import com.zeroone.star.project.dto.orgmanager.DeptDTO;
import com.zeroone.star.project.dto.orgmanager.ExportDTO;
import com.zeroone.star.project.query.orgmanager.DepartmentQuery;
import com.zeroone.star.project.query.orgmanager.DeptInfoQuery;
import com.zeroone.star.project.query.orgmanager.ExportDepartmentsQuery;
import com.zeroone.star.project.vo.JsonVO;
import lombok.SneakyThrows;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.util.List;


/**
 * @author wxs
 */
@Mapper(componentModel = "spring")
interface MsSrforgsectorMapper {
    /**
     * Srforgsector do 转换 DepartmentDTO dto
     *
     * @param srforgsector do对象
     * @return dto对象
     */
    DepartmentDTO srforgsectorToDepartmentDTO(Srforgsector srforgsector);

    List<DepartmentDTO> dosToDTOS(List<Srforgsector> srforgsectors);
}


/**
 * <p>
 * 组织部门 服务实现类
 * </p>
 *
 * @author letian
 * @since 2023-05-21
 */
@Service
@Transactional
public class SrforgsectorServiceImpl extends ServiceImpl<SrforgsectorMapper, Srforgsector> implements ISrforgsectorService {
    @Resource
    private SrforgsectorMapper srforgsectorMapper;
    @Resource
    private MsSrforgsectorMapper msSrforgsectorMapper;


    @Override
    public JsonVO<String> removeDeptByIds(DeptDTO deptDTO) {
        srforgsectorMapper.deleteDeptByIds(deptDTO);
        return JsonVO.success("删除成功！");
    }

    @Override
    public PageDTO<DepartmentDTO> listAllDepartment(DepartmentQuery query) {

        Page<Srforgsector> page = new Page<>(query.getPageIndex(), query.getPageSize());
        LambdaQueryWrapper<Srforgsector> lambdaQueryWrapper = new LambdaQueryWrapper<>();
        lambdaQueryWrapper.orderByAsc(Srforgsector::getOrdervalue);
        if (query.getName() != null) {
            lambdaQueryWrapper.like(Srforgsector::getOrgsectorname, query.getName());
        }
        Page<Srforgsector> srforgsectorPage = baseMapper.selectPage(page, lambdaQueryWrapper);
        return PageDTO.create(srforgsectorPage, x -> msSrforgsectorMapper.srforgsectorToDepartmentDTO(x));
    }

    @Override
    public DepartmentDTO queryDeptById(DeptInfoQuery query) {
        return msSrforgsectorMapper.srforgsectorToDepartmentDTO(srforgsectorMapper.selectById(query.getDeptId()));
    }

    @Resource
    private EasyExcelComponent component;

    @Resource
    private FastDfsClientComponent fastDfsClientComponent;

    @Override
    @SneakyThrows
    public ExportDTO exportDepartments(ExportDepartmentsQuery query) {
        LambdaQueryWrapper<Srforgsector> wrapper = new LambdaQueryWrapper<>();
        if (query.getDepartmentName() != null) {
            wrapper.like(Srforgsector::getOrgsectorname, query.getDepartmentName());
        }
        List<DepartmentDTO> departments = msSrforgsectorMapper.dosToDTOS(srforgsectorMapper.selectList(wrapper));
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        component.export("测试", out, DepartmentDTO.class, departments);
        FastDfsFileInfo info = fastDfsClientComponent.uploadFile(out.toByteArray(), "xlsx");
        if (info == null) {
            return null;
        }
        ExportDTO exportDTO = new ExportDTO();
        exportDTO.setUrl(fastDfsClientComponent.fetchUrl(info, "http://", true));
        return exportDTO;
    }

}
