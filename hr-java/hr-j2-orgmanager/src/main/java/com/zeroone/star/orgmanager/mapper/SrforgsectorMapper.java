package com.zeroone.star.orgmanager.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.orgmanager.entity.Srforgsector;
import com.zeroone.star.project.dto.orgmanager.DepartmentDTO;
import com.zeroone.star.project.dto.orgmanager.DeptDTO;
import com.zeroone.star.project.query.orgmanager.DepartmentQuery;
import com.zeroone.star.project.query.orgmanager.DeptQuery2;
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
     * @param deptDTO: 部门信息对象
     * @return int
     * @author 乐天
     * @description：批量删除部门信息
     * @date 2023/5/22 0:02
     */
    int deleteDepts(DeptQuery2 deptQuery2);

    /**
     * 分页查询部门信息
     * @return
     */
    List<DepartmentDTO> selectAllDepartment(DepartmentQuery query);
    void deleteDeptByIds(DeptDTO deptDTO);
}
