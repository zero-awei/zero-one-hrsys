package com.zeroone.star.sysmanager.entity;


import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.util.Date;

/**
 * The entity of {@link Menu}
 *
 * @author camille
 */
@Data
@TableName("zo_menu")
public class Menu {


    private String id;

    private String name;

    private String path;

    private Integer priority;

    private String icon;

    private String description;

    private String parent_menu_id;

    private Integer level;

    /**
     * 1: Enable 0: Not Enable
     */
    private Integer isEnable = 1;

    private String creator;

    private Date createTime;

    private Date updateTime;
}
