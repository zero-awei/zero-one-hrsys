package com.zeroone.star.sysmanager.entity;

import com.alibaba.excel.annotation.format.DateTimeFormat;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import java.io.Serializable;
import java.util.Date;

import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 角色表
 * </p>
 *
 * @author Alan
 * @since 2023-05-28
 */

@Getter
@Setter
@TableName("zo_role")
public class Role implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 唯一ID
     */
    @TableId(value = "id", type = IdType.AUTO)
    private Integer id;

    /**
     * 角色名
     */
    private String name;

    /**
     * 关键词
     */
    private String keyword;

    /**
     * 角色描述
     */
    private String description;

    /**
     * 是否启用
     */
    private Integer isEnable;
    /**
     * 创建人
     */
    private String creator;

    /**
     * 创建时间
     */

    private Date createTime;


}
