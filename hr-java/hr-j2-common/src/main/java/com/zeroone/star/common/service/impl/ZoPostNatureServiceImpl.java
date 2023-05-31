package com.zeroone.star.common.service.impl;

import com.zeroone.star.common.entity.ZoPostNature;
import com.zeroone.star.common.mapper.ZoPostNatureMapper;
import com.zeroone.star.common.service.IZoPostNatureService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.common.PostNatureDTO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 岗位性质 服务实现类
 * </p>
 *
 * @author letian
 * @since 2023-05-31
 */
@Service
public class ZoPostNatureServiceImpl extends ServiceImpl<ZoPostNatureMapper, ZoPostNature> implements IZoPostNatureService {
    @Resource
    private ZoPostNatureMapper mapper;

    @Override
    public List<PostNatureDTO> listPostNature() {
        return mapper.selectPostNature();
    }
}
