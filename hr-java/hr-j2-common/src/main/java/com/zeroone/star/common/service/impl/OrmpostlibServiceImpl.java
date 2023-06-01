package com.zeroone.star.common.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.common.entity.Ormpostlib;
import com.zeroone.star.common.mapper.OrmpostlibMapper;
import com.zeroone.star.common.service.IOrmpostlibService;
import com.zeroone.star.project.dto.common.GwTypeDTO;
import com.zeroone.star.project.dto.common.PostNatureDTO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 岗位库 服务实现类
 * </p>
 *
 * @author letian
 * @since 2023-05-21
 */
@Service
public class OrmpostlibServiceImpl extends ServiceImpl<OrmpostlibMapper, Ormpostlib> implements IOrmpostlibService {
    @Resource
    private OrmpostlibMapper ormpostlibMapper;
    @Override
    public List<GwTypeDTO> getGwType() {
        return ormpostlibMapper.selectGwtype();
    }

    @Override
    public List<PostNatureDTO> getPostNature() {
        return ormpostlibMapper.selectPostNature();
    }
}
