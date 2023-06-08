package com.zeroone.star.common.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 岗位集
 * </p>
 *
 * @author wh
 * @since 2023-05-29
 */
@Getter
@Setter
@TableName("t_ormpost")
public class TOrmpost implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 岗位集标识
     */
    private String ormpostid;

    /**
     * 岗位集名称
     */
    private String ormpostname;

    /**
     * 建立人
     */
    private String createman;

    /**
     * 更新时间
     */
    private LocalDateTime updatedate;

    /**
     * 更新人
     */
    private String updateman;

    /**
     * 建立时间
     */
    private LocalDateTime createdate;

    private Integer xh;

    /**
     * 组织标识
     */
    private String ormorgid;

    private Integer lgnx;

    private Integer qzlgnx;

    /**
     * 岗位类型
     */
    private String gwtype;

    /**
     * 岗位分类
     */
    private String gwfl;

    /**
     * 是否保密岗
     */
    private String isconfidential;

    /**
     * 是否临时数据
     */
    private String istemp;

    private Integer nx;

    private Integer bxjlnx;

    /**
     * 是否关键岗位
     */
    private String iskeypostion;

    /**
     * 岗位性质
     */
    private String postnature;

    /**
     * 启用标识
     */
    private String startstopsign;


}
