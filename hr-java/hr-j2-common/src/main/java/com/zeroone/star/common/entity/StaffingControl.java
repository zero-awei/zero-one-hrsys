package com.zeroone.star.common.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/**
 * <p>
 * 编制控制
 * </p>
 *
 * @author 浅墨
 * @since 2023-05-25
 */
@Getter
@Setter
@TableName("zo_staffing_control")
public class StaffingControl implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 编制控制ID
     */
    private String id;

    /**
     * 编制控制名称
     */
    private String name;

    /**
     * 编制控制代号
     */
    private String code;

    /**
     * 是否有效（0表示无效，1表示有效）
     */
    private Boolean isValid;


}
