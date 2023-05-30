package com.zeroone.star.orgmanager.service.impl;

import com.zeroone.star.orgmanager.entity.TOrmorgdz;
import com.zeroone.star.orgmanager.mapper.TOrmorgdzMapper;
import com.zeroone.star.orgmanager.service.ITOrmorgdzService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.j3.dto.orgmanager.OrgAddressDto;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 组织地址维护 服务实现类
 * </p>
 *
 * @author wutong
 * @since 2023-05-30
 */
@Service
public class TOrmorgdzServiceImpl extends ServiceImpl<TOrmorgdzMapper, TOrmorgdz> implements ITOrmorgdzService {

    @Override
    public boolean deleteOrgAddress(OrgAddressDto ids) {
        int flag = baseMapper.deleteBatchIds(ids.getIds());
        if (flag!=0){
            return true;
        }
        return false;
    }
}
