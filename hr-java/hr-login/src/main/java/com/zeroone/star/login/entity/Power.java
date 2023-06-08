package com.zeroone.star.login.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

/**
 * 权限表
 * @author 风月
 * @date 2023/5/31 19:16
 */
@Getter
@Setter
@TableName("zo_power")
public class Power {
    private static final long serialVersionUID = 1L;

    /**
     * 唯一ID
     */
    @TableId(value = "id", type = IdType.AUTO)
    private String id;

    /**
     * 权限名称
     */
    private String name;

    /**
     * 链接地址
     */
    private String linkUrl;

    /**
     * 显示级别
     */
    private int priority;

    /**
     * 父级权限id
     */
    private String parentRightId;

    /**
     * 层次
     */
    private int level;

    /**
     * 描述
     */
    private String description;

    /**
     * 是否启用
     */
    private int isEnable;
}
