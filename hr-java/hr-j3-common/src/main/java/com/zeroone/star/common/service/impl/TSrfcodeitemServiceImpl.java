package com.zeroone.star.common.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.common.entity.TSrfcodeitem;
import com.zeroone.star.common.mapper.TSrfcodeitemMapper;
import com.zeroone.star.common.service.ITSrfcodeitemService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.j3.dto.DropdownListOptionDTO;
import com.zeroone.star.project.j3.query.common.DisciplineTypeQuery;
import com.zeroone.star.project.j3.query.common.EducationTypeQuery;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.common.entity.TSrfcodeitem;
import com.zeroone.star.common.mapper.TSrfcodeitemMapper;
import com.zeroone.star.common.service.ITSrfcodeitemService;
import com.zeroone.star.project.j3.dto.DropdownListDTO;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 代码项 服务实现类
 * </p>
 *
 * @author H
 * @since 2023-05-28
 */
@Service
public class TSrfcodeitemServiceImpl extends ServiceImpl<TSrfcodeitemMapper, TSrfcodeitem> implements ITSrfcodeitemService {
    @Autowired
    private TSrfcodeitemMapper mapper;

    /**
     * 根据传入的代码名称返回相应的下拉菜单
     *
     * @param codeItem codeItem
     * @return {@link List< DropdownListOptionDTO>}
     * @Author H_lzu
     * @Date 13:51 2023/5/30
     */
    @Override

    public List<DropdownListOptionDTO> listDistributionStatus(String codeItem) {
        QueryWrapper<TSrfcodeitem> wrapper = new QueryWrapper<>();
        // 添加连接条件
        wrapper.inSql("CODELISTID", "SELECT CODELISTID FROM t_srfcodelist WHERE CODELISTNAME = '" + codeItem + "'");

        // 设置要查询的字段
        wrapper.select("CODEITEMID", "CODEITEMNAME");
        List<TSrfcodeitem> tSrfcodeitems = mapper.selectList(wrapper);

//        for (TSrfcodeitem item : tSrfcodeitems) {
//            System.out.println(item); // 打印对象的 toString() 方法
//        }
//        tSrfcodeitems.forEach(item -> {
//            System.out.println("Codeitemid: " + item.getCodeitemid());
//            System.out.println("Codeitemname: " + item.getCodeitemname());
//            // 打印其他属性...
//            System.out.println("------------------------");
//        });

        //转换为DTO
        List<DropdownListOptionDTO> dropdownListOptions = tSrfcodeitems.stream()
                .map(item -> new DropdownListOptionDTO(item.getCodeitemid(), item.getCodeitemname()))
                .collect(Collectors.toList());
        return dropdownListOptions;
    }
    @Override
    public List<DropdownListDTO> listLearningForms(){
        LambdaQueryWrapper<TSrfcodeitem> queryWrapper = new LambdaQueryWrapper<>();
        queryWrapper.eq(TSrfcodeitem::getCodelistid, "FC4B9F96-E6E4-4170-9587-9DB970C57AA3");
        List<TSrfcodeitem> tSrfcodeitems = baseMapper.selectList(queryWrapper);
        List<DropdownListDTO> list = new ArrayList<>();
        for (TSrfcodeitem i : tSrfcodeitems){
            DropdownListDTO dto = new DropdownListDTO();
            dto.setValue(i.getCodeitemname());
            dto.setKey(i.getCodeitemvalue());
            list.add(dto);
        }
        return list;
    }

    @Override
    public List<DropdownListDTO> listSchoolNature(){
        LambdaQueryWrapper<TSrfcodeitem> queryWrapper = new LambdaQueryWrapper<>();
        queryWrapper.eq(TSrfcodeitem::getCodelistid, "FDA27067-9E4F-4DC1-9676-2D65375359A9");
        List<TSrfcodeitem> tSrfcodeitems = baseMapper.selectList(queryWrapper);
        List<DropdownListDTO> list = new ArrayList<>();
        for (TSrfcodeitem i : tSrfcodeitems){
            DropdownListDTO dto = new DropdownListDTO();
            dto.setValue(i.getCodeitemname());
            dto.setKey(i.getCodeitemvalue());
            list.add(dto);
        }
        return list;
    }
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
