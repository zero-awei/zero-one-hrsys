package com.zeroone.star.common.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/**
 * <p>
 * 组织性质
 * </p>
 *zo_tissue_nature
 * @author abner
 * @since 2023-05-25
 */
@Getter
@Setter
@TableName("zo_tissue_nature")
public class Op implements Serializable {
    private static final long serialVersionUID = 1L;
    /**
     * 组织性质ID
     */
    private String id;
    /**
     * 组织性质
     */
    private String tissue_nature_type;

    /**
     * 组织性质状态码
     */
    private String tissue_nature_code;





}
