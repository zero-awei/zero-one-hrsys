package com.zeroone.star.common.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/**
 * <p>
 * 血型
 * </p>
 *
 * @author 浅墨
 * @since 2023-05-29
 */
@Getter
@Setter
@TableName("zo_blood_type")
public class BloodType implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 血型ID
     */
    private String id;

    /**
     * 血型名称
     */
    private String name;

    /**
     * 血型代号
     */
    private String code;

    /**
     * 是否有效（0表示无效，1表示有效）
     */
    private Boolean isValid;


}
