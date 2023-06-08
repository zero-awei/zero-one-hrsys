package com.zeroone.star.common.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/**
 * <p>
 * 所属区域
 * </p>
 *
 * @author abner
 * @since 2023-05-25
 */
@Getter
@Setter
@TableName("zo_area")
public class Or implements Serializable {
    /**
     * 所属区域ID
     */
    private String id;
    /**
     * 所属区域
     */
    private String area_type;

    /**
     * 所属区域状态码
     */
    private String area_code;
}
