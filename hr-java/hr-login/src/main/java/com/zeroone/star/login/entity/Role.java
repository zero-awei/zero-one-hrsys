package com.zeroone.star.login.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/**
 * <p>
 * 角色表
 * </p>
 *
 * @author 阿伟
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
     *  是否启用 0 禁用 1 启用
     */
    private Integer isEnable;


}
