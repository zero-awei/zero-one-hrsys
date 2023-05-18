package com.zeroone.star.common.service.impl;

import com.zeroone.star.common.entity.Pimperson;
import com.zeroone.star.common.mapper.PimpersonMapper;
import com.zeroone.star.common.service.PimpersonService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.vo.JsonVO;
import lombok.AllArgsConstructor;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 人员信息 服务实现类
 * </p>
 *
 * @author rqs
 * @since 2023-05-17
 */
@Service
@AllArgsConstructor
public class PimpersonServiceImpl extends ServiceImpl<PimpersonMapper, Pimperson> implements PimpersonService {

    @Override
    public JsonVO<String> savePimperson(String zzmm) {
        Pimperson pimPerson = new Pimperson();
        pimPerson.setZzmm(zzmm);
        int result = baseMapper.insert(pimPerson);
        if (result == 1) {
            return JsonVO.success(zzmm);
        }
        return JsonVO.fail(zzmm);
    }
}
