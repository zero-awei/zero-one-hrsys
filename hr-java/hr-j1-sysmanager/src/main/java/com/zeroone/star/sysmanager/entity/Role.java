package com.zeroone.star.sysmanager.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.util.Date;

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
    private String id;

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

    private Date updateTime;

}
