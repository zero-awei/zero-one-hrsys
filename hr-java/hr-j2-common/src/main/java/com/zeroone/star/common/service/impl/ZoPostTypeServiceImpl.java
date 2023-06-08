package com.zeroone.star.common.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.common.entity.ZoPostType;
import com.zeroone.star.common.mapper.ZoPostTypeMapper;
import com.zeroone.star.common.service.IZoPostTypeService;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 岗位分类 服务实现类
 * </p>
 *
 * @author letian
 * @since 2023-05-31
 */
@Service
public class ZoPostTypeServiceImpl extends ServiceImpl<ZoPostTypeMapper, ZoPostType> implements IZoPostTypeService {
    @Resource
    private ZoPostTypeMapper mapper;

    @Override
    public List<DropdownListOptionDTO> listPostType() {
        return mapper.selectPostType();
    }
}
