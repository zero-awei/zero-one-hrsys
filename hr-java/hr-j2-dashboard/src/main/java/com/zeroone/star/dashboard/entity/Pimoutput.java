package com.zeroone.star.dashboard.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 产值表
 * </p>
 *
 * @author wxs
 * @since 2023-05-23
 */
@Getter
@Setter
@TableName("t_pimoutput")
public class Pimoutput implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 产值标识
     */
    private String pimoutputid;

    /**
     * 建立人
     */
    private String createman;

    /**
     * 标题
     */
    private String pimoutputname;

    private Integer enable;

    /**
     * 更新人
     */
    private String updateman;

    /**
     * 建立时间
     */
    private LocalDateTime createdate;

    /**
     * 更新时间
     */
    private LocalDateTime updatedate;

    /**
     * 组织ID
     */
    private String ormorgid;

    /**
     * 年度
     */
    private String nd;

    /**
     * 月度
     */
    private String yd;

    /**
     * 产值（亿）
     */
    private Double output;


}
