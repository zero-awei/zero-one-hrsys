package com.zeroone.star.orgmanager.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.orgmanager.entity.TSrforg;
import com.zeroone.star.orgmanager.mapper.TSrforgMapper;
import com.zeroone.star.orgmanager.service.ITSrforgService;
import com.zeroone.star.project.j3.dto.AddOrgInfoDTO;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
/**
 * <p>
 * 描述：TSrforg对应MpStruct映射接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Mapper(componentModel = "spring")
interface MsTSrforgMapper {
    /**
     * AddOrgInfoDTO 转换 TSrforg dao
     * @param addOrgInfoDTO dto对象
     * @return do对象
     */
    TSrforg AddOrgInfoDTOToTSrforg(AddOrgInfoDTO addOrgInfoDTO);
}
/**
 * <p>
 * 组织机构 服务实现类
 * </p>
 *
 * @author lr
 * @since 2023-05-29
 */
@Service
public class TSrforgServiceImpl extends ServiceImpl<TSrforgMapper, TSrforg> implements ITSrforgService {

    @Resource
    MsTSrforgMapper msTSrforgMapper;

    @Override
    public void saveOryData(AddOrgInfoDTO addOrgInfoDTO) {
        //将DTO转为DAO传入
        baseMapper.insert(msTSrforgMapper.AddOrgInfoDTOToTSrforg(addOrgInfoDTO));
    }
}
