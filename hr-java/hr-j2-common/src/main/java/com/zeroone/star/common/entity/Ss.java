package com.zeroone.star.common.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/**
 * <p>
 * 补贴标准
 * </p>
 *
 * @author abner
 * @since 2023-05-25
 */
@Getter
@Setter
@TableName("zo_subsidy_standard")
public class Ss implements Serializable {
    private static final long serialVersionUID = 1L;
    /**
     * 补贴标准ID
     */
    private String id;
    /**
     * 补贴标准
     */
    private String subsidy_standard_type;

    /**
     * 补贴标准状态码
     */
    private String subsidy_standard_code;
}
