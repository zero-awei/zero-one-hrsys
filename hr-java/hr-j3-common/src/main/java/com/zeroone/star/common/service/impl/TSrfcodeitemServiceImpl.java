package com.zeroone.star.common.service.impl;

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
 * @author breezelr
 * @since 2023-05-27
 */
@Service
public class TSrfcodeitemServiceImpl extends ServiceImpl<TSrfcodeitemMapper, TSrfcodeitem> implements ITSrfcodeitemService {

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



}
