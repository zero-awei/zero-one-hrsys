package com.zeroone.star.orgmanager.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.orgmanager.entity.Srforgsector;
import com.zeroone.star.project.dto.orgmanager.DepartmentDTO;
import com.zeroone.star.project.dto.orgmanager.DeptDTO;
import com.zeroone.star.project.query.orgmanager.DepartmentQuery;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 组织部门 Mapper 接口
 * </p>
 *
 * @author letian
 * @since 2023-05-21
 */
@Mapper
public interface SrforgsectorMapper extends BaseMapper<Srforgsector> {

    /**
     * 分页查询部门信息
     *
     * @return
     */
    List<DepartmentDTO> selectAllDepartment(DepartmentQuery query);

    void deleteDeptByIds(DeptDTO deptDTO);
}
