package com.zeroone.star.orgmanager.service.impl;


import com.baomidou.mybatisplus.core.conditions.Wrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.conditions.segments.MergeSegments;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.orgmanager.entity.Ormbmkqdz;
import com.zeroone.star.orgmanager.mapper.TOrmbmkqdzMapper;
import com.zeroone.star.orgmanager.service.ITOrmbmkqdzService;
import com.zeroone.star.project.dto.orm.OrmBmkqdzDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 部门地址维护 服务实现类
 * </p>
 *
 * @author mwx
 * @since 2023-05-24
 */
@Service
public class TOrmbmkqdzServiceImpl extends ServiceImpl<TOrmbmkqdzMapper, Ormbmkqdz> implements ITOrmbmkqdzService {

    @Resource
    private TOrmbmkqdzMapper tOrmbmkqdzMapper;

    @Override
    public JsonVO<String> updateAttendanceAddress(OrmBmkqdzDTO ormBmkqdzDTO) {
        Ormbmkqdz ormbmkqdz = baseMapper.selectById(ormBmkqdzDTO.getDepartmentId());
        if (ormbmkqdz == null){
            return JsonVO.success("该地址不存在");
        }
        //设置更新时间
        ormBmkqdzDTO.setUpdatedate(LocalDateTime.now());
        System.out.println(ormBmkqdzDTO);
        int res = tOrmbmkqdzMapper.updateAttendanceAddress(ormBmkqdzDTO);
        return JsonVO.success("更新成功");
        //return res == 1 ? JsonVO.success("更新成功"):JsonVO.fail("更新失败");
    }
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.orgmanager.entity.TOrmbmkqdz;
import com.zeroone.star.orgmanager.mapper.TOrmbmkqdzMapper;
import com.zeroone.star.orgmanager.service.ITOrmbmkqdzService;

public class TOrmbmkqdzServiceImpl extends ServiceImpl<TOrmbmkqdzMapper, TOrmbmkqdz> implements ITOrmbmkqdzService {

}
