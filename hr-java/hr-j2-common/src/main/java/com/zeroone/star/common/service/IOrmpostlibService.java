package com.zeroone.star.common.service;

import com.zeroone.star.common.entity.Ormpostlib;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.common.GwTypeDTO;
import com.zeroone.star.project.dto.common.PostNatureDTO;
import com.zeroone.star.project.dto.dashboard.OrgDistributeDTO;

import java.util.List;

/**
 * <p>
 * 岗位库 服务类
 * </p>
 *
 * @author letian
 * @since 2023-05-21
 */
public interface IOrmpostlibService extends IService<Ormpostlib> {
    /**
     * @param :
     * @return List<OrgDistributeDTO>：岗位分类集合
     * @author 乐天
     * @description：获取岗位分类列表
     * @date 2023/5/22 11:04
     */
    List<GwTypeDTO> getGwType();

    /**
     * @param :
     * @return List<PostNatureDTO>：岗位性质集合
     * @author 乐天
     * @description：获取岗位性质列表
     * @date 2023/5/22 11:37
     */
    List<PostNatureDTO> getPostNature();
}
