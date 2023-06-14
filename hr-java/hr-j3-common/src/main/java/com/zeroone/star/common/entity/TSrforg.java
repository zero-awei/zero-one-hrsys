package com.zeroone.star.common.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 组织机构
 * </p>
 *
 * @author tomcatcc
 * @since 2023-06-09
 */
@Getter
@Setter
@TableName("t_srforg")
public class TSrforg implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 建立时间
     */
    private LocalDateTime createdate;

    /**
     * 建立人
     */
    private String createman;

    /**
     * 级别编码
     */
    private String levelcode;

    /**
     * 备注
     */
    private String memo;

    /**
     * 组织编号
     */
    private String orgcode;

    /**
     * 组织机构标识
     */
    private String orgid;

    /**
     * 组织机构名称
     */
    private String orgname;

    /**
     * 组织机构
     */
    private String porgid;

    /**
     * 保留字段
     */
    private String reserver;

    /**
     * 保留字段10
     */
    private String reserver10;

    private Integer reserver11;

    private Integer reserver12;

    private Integer reserver13;

    private Integer reserver14;

    private Integer reserver15;

    private Integer reserver16;

    private Integer reserver17;

    private Integer reserver18;

    /**
     * 保留字段19
     */
    private LocalDateTime reserver19;

    /**
     * 保留字段2
     */
    private String reserver2;

    /**
     * 保留字段20
     */
    private LocalDateTime reserver20;

    /**
     * 保留字段21
     */
    private LocalDateTime reserver21;

    /**
     * 保留字段22
     */
    private LocalDateTime reserver22;

    /**
     * 保留字段23
     */
    private String reserver23;

    /**
     * 保留字段24
     */
    private String reserver24;

    /**
     * 保留字段25
     */
    private String reserver25;

    /**
     * 保留字段26
     */
    private String reserver26;

    /**
     * 保留字段27
     */
    private String reserver27;

    /**
     * 保留字段28
     */
    private String reserver28;

    /**
     * 保留字段29
     */
    private String reserver29;

    /**
     * 保留字段3
     */
    private String reserver3;

    /**
     * 保留字段30
     */
    private String reserver30;

    /**
     * 保留字段4
     */
    private String reserver4;

    /**
     * 保留字段5
     */
    private String reserver5;

    /**
     * 保留字段6
     */
    private String reserver6;

    /**
     * 保留字段7
     */
    private String reserver7;

    /**
     * 保留字段8
     */
    private String reserver8;

    /**
     * 保留字段9
     */
    private String reserver9;

    /**
     * 简称
     */
    private String shortname;

    /**
     * 更新时间
     */
    private LocalDateTime updatedate;

    /**
     * 更新人
     */
    private String updateman;

    /**
     * 用户数据
     */
    private String userdata;

    /**
     * 用户数据2
     */
    private String userdata2;

    private Integer validflag;

    private Integer virtualflag;

    /**
     * 组织类型
     */
    private String zzlx;

    /**
     * 所属OU
     */
    private String ssou;

    /**
     * 所属区域
     */
    private String gsss;

    /**
     * 组织地址编码
     */
    private String zzdzbm;

    /**
     * 组织地址一
     */
    private String zzdzy;

    /**
     * 组织地址二
     */
    private String zzdze;

    /**
     * 组织创建时间
     */
    private LocalDateTime zzcjsj;

    /**
     * 组织显示名称
     */
    private String zzdzs;

    private Integer px;

    /**
     * 区域补贴
     */
    private String btqy;

    private Integer xn;

    /**
     * ERP组织ID
     */
    private String erporgid;

    /**
     * 启停标识
     */
    private String startstopsign;

    /**
     * 组织性质
     */
    private String legalentity;

    /**
     * 对应OU
     */
    private String correspondingorg;

    /**
     * 公司根组织ID
     */
    private String companyflag;


}
