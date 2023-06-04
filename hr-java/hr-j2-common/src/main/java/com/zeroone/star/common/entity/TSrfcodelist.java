package com.zeroone.star.common.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 代码表
 * </p>
 *
 * @author 浅墨
 * @since 2023-06-04
 */
@Getter
@Setter
@TableName("t_srfcodelist")
public class TSrfcodelist implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 代码表模型
     */
    private String clmodel;

    /**
     * 代码表参数
     */
    private String clparam;

    /**
     * 配置路径
     */
    private String clpath;

    private Integer clversion;

    /**
     * 代码表标识
     */
    private String codelistid;

    /**
     * 代码表名称
     */
    private String codelistname;

    /**
     * 建立时间
     */
    private LocalDateTime createdate;

    /**
     * 建立人
     */
    private String createman;

    /**
     * 数据实体
     */
    private String deid;

    /**
     * 空白显示内容
     */
    private String emptytext;

    /**
     * 数据库填充器
     */
    private String filler;

    private Integer issystem;

    private Integer isuserscope;

    /**
     * 备注
     */
    private String memo;

    private Integer novalueempty;

    /**
     * 或模式
     */
    private String ormode;

    /**
     * 保留字段
     */
    private String reserver;

    /**
     * 保留字段2
     */
    private String reserver2;

    /**
     * 保留字段3
     */
    private String reserver3;

    /**
     * 保留字段4
     */
    private String reserver4;

    /**
     * 保留字段5
     */
    private LocalDateTime reserver5;

    /**
     * 显示分割符号
     */
    private String seperator;

    private Integer srfsyspub;

    private Integer srfuserpub;

    /**
     * 更新时间
     */
    private LocalDateTime updatedate;

    /**
     * 更新人
     */
    private String updateman;

    /**
     * 值分割符号
     */
    private String valueseperator;


}
