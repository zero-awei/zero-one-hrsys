package com.zeroone.star.common.mapper;


import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.common.entity.DocumentType;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * 证件类型 Mapper 接口
 * </p>
 *
 * @author 浅墨
 * @since 2023-05-24
 */
@Mapper
public interface DocumentTypeMapper extends BaseMapper<DocumentType> {

    @Select("select `code` AS `key`, `name` AS `value` from zo_document_type;")
    List<DropdownListOptionDTO> selectDocumentType();
}
