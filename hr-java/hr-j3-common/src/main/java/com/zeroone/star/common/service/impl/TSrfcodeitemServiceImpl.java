package com.zeroone.star.common.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.zeroone.star.common.entity.TSrfcodeitem;
import com.zeroone.star.common.mapper.TSrfcodeitemMapper;
import com.zeroone.star.common.service.ITSrfcodeitemService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.j3.query.common.DisciplineTypeQuery;
import com.zeroone.star.project.j3.query.common.EducationTypeQuery;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 代码项 服务实现类
 * </p>
 *
 * @author wutong
 * @since 2023-05-30
 */
@Service
public class TSrfcodeitemServiceImpl extends ServiceImpl<TSrfcodeitemMapper, TSrfcodeitem> implements ITSrfcodeitemService {

    @Override
    public List<String> listEducationType(EducationTypeQuery education) {
        //创建条件
        LambdaQueryWrapper<TSrfcodeitem> queryWrapper = new LambdaQueryWrapper<>();
        //获取id
        queryWrapper.eq(TSrfcodeitem::getCodelistid, education.getCode());
        //查询数据
        List<TSrfcodeitem> tSrfcodeitems = baseMapper.selectList(queryWrapper);
        //创建返回结果集合
        List<String> list = new ArrayList<>();
        if (tSrfcodeitems.size()>0) {
            for (TSrfcodeitem tSrfcodeitem : tSrfcodeitems) {
                String name = tSrfcodeitem.getCodeitemname();
                list.add(name);
            }
        }
        return list;
    }

    @Override
    public List<String> listDisciplineType(DisciplineTypeQuery discipline) {
        //创建条件
        LambdaQueryWrapper<TSrfcodeitem> queryWrapper = new LambdaQueryWrapper<>();
        //获取id
        queryWrapper.eq(TSrfcodeitem::getCodelistid, discipline.getCode());
        //查询数据
        List<TSrfcodeitem> tSrfcodeitems = baseMapper.selectList(queryWrapper);
        //创建返回结果集合
        List<String> list = new ArrayList<>();
        if (tSrfcodeitems.size()>0) {
            for (TSrfcodeitem tSrfcodeitem : tSrfcodeitems) {
                String name = tSrfcodeitem.getCodeitemname();
                list.add(name);
            }
        }
        return list;

    }
}
