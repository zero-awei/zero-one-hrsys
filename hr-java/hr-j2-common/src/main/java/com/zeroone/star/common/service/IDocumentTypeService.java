package com.zeroone.star.common.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.common.entity.DocumentType;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;

import java.util.List;

/**
 * <p>
 * 证件类型 服务类
 * </p>
 *
 * @author 浅墨
 * @since 2023-05-24
 */
public interface IDocumentTypeService extends IService<DocumentType> {

    List<DropdownListOptionDTO> listDocumentType();
}
