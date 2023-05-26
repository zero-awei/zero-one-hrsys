package com.zeroone.star.sysmanager.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

/**
 * The entity of {@link Right}
 *
 * @author authoralankay
 */
@Data
@TableName("zo_power")
public class Right {

    @TableId(value = "id", type = IdType.AUTO)
    private String id;

    private String name;

    @TableField("link_url")
    private String linkUrl;

    private Integer priority;

    @TableField("parent_right_id")
    private String parentRightId;

    private Integer level;

    private String description;

    /**
     * 1: Enable 0: Not Enable
     */
    @TableField("is_enable")
    private Integer isEnable;
}
