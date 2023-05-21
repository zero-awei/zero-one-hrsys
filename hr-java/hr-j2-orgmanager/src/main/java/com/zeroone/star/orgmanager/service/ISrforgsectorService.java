package com.zeroone.star.orgmanager.service;

import com.zeroone.star.orgmanager.entity.Srforgsector;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.query.orgmanager.DeptQuery1;
import com.zeroone.star.project.query.orgmanager.DeptQuery2;

/**
 * <p>
 * 组织部门 服务类
 * </p>
 *
 * @author letian
 * @since 2023-05-21
 */
public interface ISrforgsectorService extends IService<Srforgsector> {
    /**
     * @param deptQuery1:部门信息对象（id）
     * @return Boolean
     * @author 乐天
     * @description：根据id删除指定部门信息
     * @date 2023/5/22 0:04
     */
    Boolean removeDeptById(DeptQuery1 deptQuery1);

    /**
     * @param deptQuery2:部门信息对象（ids）
     * @return Boolean
     * @author 乐天
     * @description：根据ids批量删除部门信息
     * @date 2023/5/22 0:04
     */
    Boolean removeDepts(DeptQuery2 deptQuery2);
}
