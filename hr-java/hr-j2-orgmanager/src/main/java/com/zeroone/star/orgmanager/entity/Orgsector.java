package com.zeroone.star.orgmanager.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import com.zeroone.star.orgmanager.entity.myutils.SnowflakeIdGenerator;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

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
@TableName("t_srforgsector")
public class Orgsector implements Serializable {


    private static final long serialVersionUID = 1L;

    /**
     * 条线代码
     */
    private String bizcode;

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

    private Integer ordervalue;

    /**
     * 部门组织编号
     */
    private String orgcode;

    /**
     * 组织机构
     */
    private String orgid;

    /**
     * 组织机构
     */
    private String orgname;

    /**
     * 部门标识：主键
     */
    private String orgsectorid;

    /**
     * 部门名称
     */
    private String orgsectorname;

    /**
     * 上级部门
     */
    private String porgsectorid;

    /**
     * 上级部门
     */
    private String porgsectorname;

    /**
     * 汇报部门
     */
    private String reporgsectorid;

    /**
     * 汇报部门
     */
    private String reporgsectorname;

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
     * 地区分类
     */
    private String qy;

    /**
     * 部门类型
     */
    private String bmlx;

    /**
     * 项目ID
     */
    private String ormxmglid;

    private Integer shgwsl;

    private Integer shzwsl;

    private Integer bmbzrs;

    private Integer bmsjbzrs;

    /**
     * 项目部类型
     */
    private String xmblx;

    /**
     * 管控机制
     */
    private String gkjz;

    /**
     * 部门负责人ID
     */
    private String pimpersonid;

    /**
     * 项目规模
     */
    private String xmgm;

    /**
     * 项目标签
     */
    private String xmbq;

    /**
     * 项目类型
     */
    private String xmlx;

    /**
     * 对项目经理的要求
     */
    private String dxmjlyq;

    /**
     * 对项目总工的要求
     */
    private String dxmzgyq;

    /**
     * 打卡方式
     */
    private String dkfs;

    /**
     * 工期安排
     */
    private String gqap;

    /**
     * 项目基本情况
     */
    private String xmjbqk;

    /**
     * 工程名称及编码
     */
    private String gcmcjbm;

    /**
     * 项目类型（其他）
     */
    private String xmlxqt;

    /**
     * 上班考勤时间
     */
    private LocalDateTime kqkssj;

    /**
     * 下班考勤时间
     */
    private LocalDateTime kqjssj;

    /**
     * 考勤员标识
     */
    private String pimpersonid2;

    /**
     * 计划成本（万）
     */
    private Double jhcb;

    /**
     * 实际成本（万）
     */
    private Double sjcb;

    /**
     * 计划人月
     */
    private Double jhry;

    /**
     * 实际人月
     */
    private Double sjry;

    /**
     * 上班时间
     */
    private LocalDateTime sbsj;

    /**
     * 下班时间
     */
    private LocalDateTime xbsj;

    /**
     * 所属OU
     */
    private String belongou;

    /**
     * 所属区域
     */
    private String belongregion;

    /**
     * ERP部门ID
     */
    private String erporgid;

    /**
     * 启停标识
     */
    private String startstopsign;

    /**
     * 参照职务层级
     */
    private String referjoblevel;

    /**
     * 项目部ID
     */
    private String prodepid;

    /**
     * 头衔
     */
    private String title;

    /**
     * 组织类型
     */
    private String orgtype;

    /**
     * 考勤设置标识
     */
    private String attendencesetupid;

    /**
     * 项目负责人ID
     */
    private String proleaderid;

    /**
     * 审批状态
     */
    private String approvalstatus;

    /**
     * 版本
     */
    private Double edition;

    /**
     * 原纪录ID
     */
    private String oldid;

    /**
     * 版本状态
     */
    private String editionstate;

    private Integer sjrs;

    private Integer gwsl;

    private Integer zwsl;

    public void generateOrgSectorId() {
        long workerId = 0L; // 每个节点应该使用唯一的workerId
        long datacenterId = 0L; // 每个数据中心应该使用唯一的datacenterId
        SnowflakeIdGenerator idGenerator = new SnowflakeIdGenerator(workerId, datacenterId);
        this.orgsectorid = String.valueOf(idGenerator.nextId());
    }
}



