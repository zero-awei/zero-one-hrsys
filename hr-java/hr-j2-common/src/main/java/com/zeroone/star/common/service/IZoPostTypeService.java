package com.zeroone.star.common.service;

import com.zeroone.star.common.entity.ZoPostType;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.common.PostNatureDTO;
import com.zeroone.star.project.dto.common.PostTypeDTO;

import java.util.List;

/**
 * <p>
 * 岗位分类 服务类
 * </p>
 *
 * @author letian
 * @since 2023-05-31
 */
public interface IZoPostTypeService extends IService<ZoPostType> {

    List<PostTypeDTO> listPostType();


}
