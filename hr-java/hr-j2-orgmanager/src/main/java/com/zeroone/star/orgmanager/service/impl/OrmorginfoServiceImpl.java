package com.zeroone.star.orgmanager.service.impl;

import com.zeroone.star.orgmanager.entity.Ormorginfo;
import com.zeroone.star.orgmanager.mapper.OrmorginfoMapper;
import com.zeroone.star.orgmanager.service.IOrmorginfoService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.orgmanager.DeptInfoDTO;
import com.zeroone.star.project.vo.JsonVO;
import lombok.AllArgsConstructor;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 组织信息 服务实现类
 * </p>
 *
 * @author rqs
 * @since 2023-05-19
 */
@Service
@AllArgsConstructor
public class OrmorginfoServiceImpl extends ServiceImpl<OrmorginfoMapper, Ormorginfo> implements IOrmorginfoService {

    @Override
    public JsonVO<String> saveDept(DeptInfoDTO deptInfoDTO) {
        return null;
    }
}
