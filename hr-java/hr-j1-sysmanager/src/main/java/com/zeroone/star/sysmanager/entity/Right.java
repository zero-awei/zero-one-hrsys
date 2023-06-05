package com.zeroone.star.sysmanager.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.util.Date;

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

    private String linkUrl;

    private Integer priority;

    private String parentRightId;

    private Integer level;

    private String description;

    /**
     * 1: Enable 0: Not Enable
     */
    private Integer isEnable;

    private String creator;

    private Date createTime;

    private Date updateTime;

}
