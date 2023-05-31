package com.zeroone.star.orgmanager.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import java.util.UUID;

import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 组织部门
 * </p>
 *
 * @author rqs
 * @since 2023-05-23
 */
@Getter
@Setter
@TableName("t_orgsector")
public class Orgsector implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 项目基本情况
     */
    private String xmjbqk;

    /**
     * 更新人
     */
    private String updateman;

    private Integer ordervalue;

    /**
     * 地区分类
     */
    private String qy;

    /**
     * 版本
     */
    private Double edition;

    /**
     * 上班时间
     */
    private LocalDateTime sbsj;

    /**
     * 下班时间
     */
    private LocalDateTime xbsj;

    /**
     * 启停标识
     */
    private String startstopsign;

    private Integer bmbzrs;

    /**
     * 建立时间
     */
    private LocalDateTime createdate;

    private Integer bmsjbzrs;

    /**
     * 工程名称及编码
     */
    private String gcmcjbm;

    /**
     * 项目标签
     */
    private String xmbq;

    /**
     * 原纪录ID
     */
    private String oldid;

    /**
     * 上班考勤时间
     */
    private LocalDateTime kqkssj;

    /**
     * 部门组织编号
     */
    private String orgcode;

    /**
     * 计划人月
     */
    private Double jhry;

    /**
     * 审批状态
     */
    private String approvalstatus;

    /**
     * 下班考勤时间
     */
    private LocalDateTime kqjssj;

    /**
     * 更新时间
     */
    private LocalDateTime updatedate;

    /**
     * 项目类型
     */
    private String xmlx;

    /**
     * 组织类型
     */
    private String orgtype;

    /**
     * ERP部门ID
     */
    private String erporgid;

    /**
     * 打卡方式
     */
    private String dkfs;

    /**
     * 项目类型（其他）
     */
    private String xmlxqt;

    private Integer sjrs;

    /**
     * 部门名称
     */
    private String orgsectorname;

    private Integer zwsl;

    private Integer shgwsl;

    /**
     * 项目规模
     */
    private String xmgm;

    private Integer gwsl;

    /**
     * 对项目经理的要求
     */
    private String dxmjlyq;

    /**
     * 对项目总工的要求
     */
    private String dxmzgyq;

    /**
     * 头衔
     */
    private String title;

    private Integer validflag;

    /**
     * 参照职务层级
     */
    private String referjoblevel;

    /**
     * 所属OU
     */
    private String belongou;

    private Integer shzwsl;

    /**
     * 简称
     */
    private String shortname;

    /**
     * 工期安排
     */
    private String gqap;

    /**
     * 计划成本（万）
     */
    private Double jhcb;

    /**
     * 部门类型
     */
    private String bmlx;

    /**
     * 项目部类型
     */
    private String xmblx;

    /**
     * 部门标识
     */
    private String orgsectorid;

    /**
     * 管控机制
     */
    private String gkjz;

    /**
     * 版本状态
     */
    private String editionstate;

    /**
     * 建立人
     */
    private String createman;

    /**
     * 实际成本（万）
     */
    private Double sjcb;

    /**
     * 实际人月
     */
    private Double sjry;

    /**
     * 所属区域
     */
    private String belongregion;

    /**
     * 部门负责人ID
     */
    private String pimpersonid;

    /**
     * 项目ID
     */
    private String ormxmglid;

    /**
     * 项目部ID
     */
    private String prodepid;

    /**
     * 项目负责人ID
     */
    private String proleaderid;

    /**
     * 上级部门
     */
    private String porgsectorid;

    /**
     * 组织机构
     */
    private String orgid;

    /**
     * 编制控制
     */
    private Integer bzkz;//此处修改了原表的字段

    /**
     * 保留字段29
     */
    private String reserver29;

    /**
     * 保留字段25
     */
    private String reserver25;

    private Integer reserver15;

    /**
     * 保留字段9
     */
    private String reserver9;

    private Integer reserver13;

    /**
     * 保留字段23
     */
    private String reserver23;

    /**
     * 条线代码
     */
    private String bizcode;

    /**
     * 保留字段24
     */
    private String reserver24;

    /**
     * 用户数据
     */
    private String userdata;

    /**
     * 级别编码
     */
    private String levelcode;

    /**
     * 保留字段21
     */
    private LocalDateTime reserver21;

    /**
     * 用户数据2
     */
    private String userdata2;

    /**
     * 保留字段22
     */
    private LocalDateTime reserver22;

    private Integer reserver14;

    /**
     * 保留字段30
     */
    private String reserver30;

    /**
     * 保留字段7
     */
    private String reserver7;

    /**
     * 保留字段2
     */
    private String reserver2;

    /**
     * 备注
     */
    private String memo;

    private Integer reserver12;

    /**
     * 保留字段
     */
    private String reserver;

    /**
     * 保留字段27
     */
    private String reserver27;

    /**
     * 保留字段3
     */
    private String reserver3;

    private Integer reserver18;

    private Integer virtualflag;

    private Integer reserver11;

    /**
     * 保留字段26
     */
    private String reserver26;

    /**
     * 保留字段10
     */
    private String reserver10;

    /**
     * 保留字段8
     */
    private String reserver8;

    private Integer reserver16;

    /**
     * 保留字段19
     */
    private LocalDateTime reserver19;

    /**
     * 保留字段20
     */
    private LocalDateTime reserver20;

    /**
     * 保留字段5
     */
    private String reserver5;

    private Integer reserver17;

    /**
     * 保留字段28
     */
    private String reserver28;

    /**
     * 保留字段6
     */
    private String reserver6;

    /**
     * 组织机构
     */
    private String orgname;

    /**
     * 上级部门
     */
    private String porgsectorname;

    /**
     * 汇报部门
     */
    private String reporgsectorname;

    /**
     * 汇报部门
     */
    private String reporgsectorid;

    public void generateOrgSectorId() {
        this.orgsectorid = UUID.randomUUID().toString();
    }
}



