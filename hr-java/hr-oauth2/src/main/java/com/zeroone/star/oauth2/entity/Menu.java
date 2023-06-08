package com.zeroone.star.oauth2.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/**
 * <p>
 * zo_menu 菜单表
 * </p>
 *
 * @author 风月
 */
@Getter
@Setter
@TableName("zo_menu")
public class Menu implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 菜单编号
     */
    @TableId(value = "id", type = IdType.AUTO)
    private Integer id;

    /**
     * 菜单名
     */
    private String name;

//    /**
//     * 链接地址
//     */
//    private String linkUrl;

    /**
     * 路由地址
     */
    private String path;

    /**
     * 显示优先级别
     */
    private Integer priority;

    /**
     * 图标
     */
    private String icon;

    /**
     * 描述
     */
    private String description;

    /**
     * 父级菜单编号
     */
    private Integer parentMenuId;

    /**
     * 层次级别
     */
    private Integer level;

    /**
     * 是否启用 0 禁用 1 启用
     */
    private Integer isEnable;


}
