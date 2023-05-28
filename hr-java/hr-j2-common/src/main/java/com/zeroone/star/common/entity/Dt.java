package com.zeroone.star.common.entity;


import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/**
 * <p>
 * 部门类型
 * </p>
 *
 * @author abner
 * @since 2023-05-25
 */
@Getter
@Setter
@TableName("zo_sector_type")
public class Dt implements Serializable {
    private static final long serialVersionUID = 1L;
    /**
     * 部门类型ID
     */
    private String id;
    /**
     * 部门类型
     */
    private String sector_type;

    /**
     * 部门类型状态码
     */
    private String sector_type_code;



}
