package com.zeroone.star.common.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.common.entity.TOrgsector;
import com.zeroone.star.project.j3.dto.DropdownListDTO;
import com.zeroone.star.project.j3.query.common.SectorNameQuery;

import java.util.List;

/**
 * <p>
 * 组织部门 服务类
 * </p>
 *
 * @author breezelr
 * @since 2023-05-27
 */
public interface ITOrgsectorService extends IService<TOrgsector> {

    /**
     * 部门名称下拉列表
     * 库： t_orgSector
     *
     * @param sectorNameQuery 组织id和部门关键字
     * @return 查询对象
     */
    List<DropdownListDTO> listSectorName(SectorNameQuery sectorNameQuery);
}
