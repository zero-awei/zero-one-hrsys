package com.zeroone.star.common.entity;


import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/**
 * <p>
 * 证件类型
 * </p>
 *
 * @author 浅墨
 * @since 2023-05-24
 */
@Getter
@Setter
@TableName("zo_document_type")
public class DocumentType implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 证件类型ID
     */
    private String id;

    /**
     * 证件类型名称
     */
    private String name;

    /**
     * 证件类型代号
     */
    private String code;

    /**
     * 是否有效（0表示无效，1表示有效）
     */
    private Boolean isValid;


}
