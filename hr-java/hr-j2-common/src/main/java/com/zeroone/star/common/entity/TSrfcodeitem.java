package com.zeroone.star.common.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 代码项
 * </p>
 *
 * @author 浅墨
 * @since 2023-06-04
 */
@Getter
@Setter
@TableName("t_srfcodeitem")
public class TSrfcodeitem implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 代码项标识
     */
    private String codeitemid;

    /**
     * 代码项名称
     */
    private String codeitemname;

    /**
     * 代码项值
     */
    private String codeitemvalue;

    /**
     * 代码表
     */
    private String codelistid;

    /**
     * 建立时间
     */
    private LocalDateTime createdate;

    /**
     * 建立人
     */
    private String createman;

    /**
     * 备注
     */
    private String memo;

    private Integer ordervalue;

    /**
     * 上级代码项
     */
    private String pcodeitemid;

    /**
     * 快捷输入
     */
    private String shortkey;

    /**
     * 更新时间
     */
    private LocalDateTime updatedate;

    /**
     * 更新人
     */
    private String updateman;

    /**
     * 保留字段
     */
    private String reserver;

    /**
     * 保留字段2
     */
    private String reserver2;

    private Integer reserver3;

    private Integer reserver4;

    /**
     * 保留字段5
     */
    private LocalDateTime reserver5;


}
