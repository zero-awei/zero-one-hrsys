package com.zeroone.star.orgmanager.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.orgmanager.entity.TOrmorginfo;
import com.zeroone.star.orgmanager.mapper.TOrmorginfoMapper;
import com.zeroone.star.orgmanager.service.ITOrmorginfoService;
import com.zeroone.star.project.j3.dto.AddOrgInfoDTO;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

@Mapper(componentModel = "spring")
interface MsTOrmorginfoMapper {
    /**
     * AddOrgInfoDTO 转换 TOrmorginfo dao
     * @param addOrgInfoDTO dto对象
     * @return do对象
     */
    TOrmorginfo AddOrgInfoDTOToOrmorginfo(AddOrgInfoDTO addOrgInfoDTO);
}

/**
 * <p>
 * 组织信息 服务实现类
 * </p>
 *
 * @author breezelr
 * @since 2023-05-27
 */
@Service
public class TOrmorginfoServiceImpl extends ServiceImpl<TOrmorginfoMapper, TOrmorginfo> implements ITOrmorginfoService {

    @Resource
    MsTOrmorginfoMapper msTOrmorginfoMapper;

    @Override
    public void saveOryData(AddOrgInfoDTO addOrgInfoDTO) {
        baseMapper.insert(msTOrmorginfoMapper.AddOrgInfoDTOToOrmorginfo(addOrgInfoDTO));
    }
}
