package com.zeroone.star.common.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.common.entity.Zzmm;
import com.zeroone.star.common.mapper.ZzmmMapper;
import com.zeroone.star.common.service.ZzmmService;
import com.zeroone.star.project.dto.common.ZzmmDTO;
import lombok.AllArgsConstructor;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * 描述：
 * 文件名：zzmmServiceImpl
 * 创建者：rqs
 * 创建时间：2023/5/19 23:11
 */
@Service
@AllArgsConstructor
public class ZzmmServiceImpl extends ServiceImpl<ZzmmMapper, Zzmm> implements ZzmmService {

    @Resource
    private ZzmmMapper zzmmMapper;
    @Override
    public List<ZzmmDTO> getZzmm() {
        List<ZzmmDTO> zzmmDTOList = zzmmMapper.selectZzmmList();
        return zzmmDTOList;
    }

}
