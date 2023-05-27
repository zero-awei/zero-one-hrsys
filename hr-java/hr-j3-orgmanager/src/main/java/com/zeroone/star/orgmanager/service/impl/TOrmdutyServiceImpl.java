package com.zeroone.star.orgmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.orgmanager.entity.TOrmduty;
import com.zeroone.star.orgmanager.mapper.TOrmdutyMapper;
import com.zeroone.star.orgmanager.service.ITOrmdutyService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j3.dto.JobDTO;
import com.zeroone.star.project.j3.query.JobByNameQuery;
import org.apache.commons.lang.StringUtils;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：TOrmduty对应MpStruct映射接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Mapper(componentModel = "spring")
interface MsJobMapper {
    /**
     * TOrmduty do 转换 job dto
     * @param tOrmduty do对象
     * @return dto对象
     */
    JobDTO TOrmdutyToJobDto(TOrmduty tOrmduty);
}

/**
 * <p>
 * 职务管理 服务实现类
 * </p>
 *
 * @author breezelr
 * @since 2023-05-27
 */
@Service
public class TOrmdutyServiceImpl extends ServiceImpl<TOrmdutyMapper, TOrmduty> implements ITOrmdutyService {

    @Resource
    MsJobMapper msJobMapper;
    @Override
    public PageDTO<JobDTO> listJobByName(JobByNameQuery condition) {
        // 构建分页对象
        Page<TOrmduty> page = new Page<>(condition.getPageIndex(), condition.getPageSize());
        // 构建查询条件
        QueryWrapper<TOrmduty> wrapper = new QueryWrapper<>();
        wrapper.like(StringUtils.isNotBlank(condition.getName()),"ORMDUTYNAME", condition.getName());
        // 执行分页查询
        Page<TOrmduty> pageResult = baseMapper.selectPage(page, wrapper);
        return PageDTO.create(pageResult, TOrmduty -> msJobMapper.TOrmdutyToJobDto(TOrmduty));
    }
}
