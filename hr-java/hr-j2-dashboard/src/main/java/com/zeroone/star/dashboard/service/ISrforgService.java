package com.zeroone.star.dashboard.service;

import com.zeroone.star.dashboard.entity.Srforg;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.dashboard.OrgDistributeDTO;
import com.zeroone.star.project.dto.dashboard.OrgEmployeeCountDTO;

import java.util.List;

/**
 * <p>
 * 组织机构 服务类
 * </p>
 *
 * @author letian
 * @since 2023-05-21
 */
public interface ISrforgService extends IService<Srforg> {
    /**
     * @param :
     * @return List<String>：组织集合
     * @author 乐天
     * @description:查询所有的组织
     * @date 2023/5/22 1:17
     */
    List<OrgDistributeDTO> getAllOrg();

    /**
     * @param :
     * @return Integer：组织人数
     * @author 乐天
     * @description：获取组织人数
     * @date 2023/5/22 1:18
     */
    List<OrgEmployeeCountDTO> getOrgCount();
}
