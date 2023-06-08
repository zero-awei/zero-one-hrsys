package com.zeroone.star.common.service;

import com.zeroone.star.common.entity.TSrforgsector;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.j3.dto.DropdownListDTO;
import com.zeroone.star.project.j3.query.common.SectorNameQuery;

import java.util.List;

/**
 * <p>
 * 组织部门 服务类
 * </p>
 *
 * @author lr
 * @since 2023-05-29
 */
public interface ITSrforgsectorService extends IService<TSrforgsector> {
    /**
     * 部门名称下拉列表
     * 库： t_srforgsector
     *
     * @param sectorNameQuery 组织id和部门关键字
     * @return 查询对象
     */
    List<DropdownListDTO> listSectorName(SectorNameQuery sectorNameQuery);
}
