package com.zeroone.star.common.service.impl;


import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.common.entity.DocumentType;
import com.zeroone.star.common.mapper.DocumentTypeMapper;
import com.zeroone.star.common.service.IDocumentTypeService;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;


/**
 * <p>
 * 证件类型 服务实现类
 * </p>
 *
 * @author 浅墨
 * @since 2023-05-24
 */
@Service
public class DocumentTypeServiceImpl extends ServiceImpl<DocumentTypeMapper, DocumentType> implements IDocumentTypeService {

    @Resource
    private DocumentTypeMapper mapper;

    @Override
    public List<DropdownListOptionDTO> listDocumentType() {
        return mapper.selectDocumentType();
    }
}
