package com.zeroone.star.common.service;

import com.zeroone.star.common.entity.ZoPostNature;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.common.PostNatureDTO;

import java.util.List;

/**
 * <p>
 * 岗位性质 服务类
 * </p>
 *
 * @author letian
 * @since 2023-05-31
 */
public interface IZoPostNatureService extends IService<ZoPostNature> {

    List<PostNatureDTO> listPostNature();
}
