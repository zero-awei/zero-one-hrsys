package com.zeroone.star.common.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 人员信息
 * </p>
 *
 * @author wxs
 * @since 2023-05-23
 */
@Getter
@Setter
@TableName("t_pimperson")
public class Pimperson implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 人员信息标识
     */
    private String pimpersonid;

    private Integer enable;

    /**
     * 员工姓名
     */
    private String pimpersonname;

    /**
     * 建立人
     */
    private String createman;

    /**
     * 更新人
     */
    private String updateman;

    /**
     * 更新时间
     */
    private LocalDateTime updatedate;

    /**
     * 建立时间
     */
    private LocalDateTime createdate;

    /**
     * 员工编号
     */
    private String ygbh;

    /**
     * 系统编号
     */
    private String xtbh;

    /**
     * 员工类型
     */
    private String yglx;

    /**
     * 曾用名
     */
    private String cym;

    /**
     * 证件类型
     */
    private String zjlx;

    /**
     * 证件号码
     */
    private String zjhm;

    /**
     * 性别
     */
    private String xb;

    /**
     * 出生日期
     */
    private LocalDateTime csrq;

    private Integer nl;

    /**
     * 血型
     */
    private String xx;

    /**
     * 民族
     */
    private String mz;

    /**
     * 婚姻状况
     */
    private String hyzk;

    /**
     * 手机号码
     */
    private String lxdh;

    /**
     * 电子邮箱
     */
    private String dzyx;

    /**
     * 籍贯
     */
    private String jg;

    /**
     * 出生地
     */
    private String csd;

    /**
     * 户籍所在地
     */
    private String hjszd;

    /**
     * 户口类型
     */
    private String hklx;

    /**
     * 爱好特长
     */
    private String ahtc;

    /**
     * 参加工作时间
     */
    private LocalDateTime cjgzsj;

    /**
     * 到局时间
     */
    private LocalDateTime dzjbjsj;

    /**
     * 到本单位时间
     */
    private LocalDateTime dbdwsj;

    /**
     * 入职渠道
     */
    private String rzqd;

    /**
     * 政治面貌
     */
    private String zzmm;

    /**
     * 入党时间
     */
    private LocalDateTime rdsj;

    /**
     * 入团时间
     */
    private LocalDateTime rtsj;

    /**
     * 合同签订次数
     */
    private String htqdcs;

    /**
     * 员工状态
     */
    private String ygzt;

    /**
     * 专家类型
     */
    private String zj;

    /**
     * 挂职状态
     */
    private String gzzt;

    /**
     * 在岗状态
     */
    private String zgzt;

    /**
     * 挂职开始时间
     */
    private LocalDateTime gzkssj;

    /**
     * 挂职结束时间
     */
    private LocalDateTime gzjssj;

    /**
     * 见习期“业务导师”
     */
    private String jxsywds;

    /**
     * 同步员工信息
     */
    private String sftberp;

    /**
     * 见习期“思想导师”
     */
    private String jxssxds;

    /**
     * 有独生子女证
     */
    private String sfdszn;

    /**
     * 职级
     */
    private String rank;

    /**
     * 组织
     */
    private String zz;

    /**
     * 部门
     */
    private String bm;

    /**
     * 照片
     */
    private String zp;

    /**
     * 岗位
     */
    private String gw;

    /**
     * 职务
     */
    private String zw;

    /**
     * 执业资格类别编码
     */
    private String pimqualtypeid;

    /**
     * 执业资格专业编码
     */
    private String pimqualmajorid;

    private Integer hmd;

    /**
     * 见习到期时间
     */
    private LocalDateTime jxdq;

    /**
     * 试用到期时间
     */
    private LocalDateTime sydq;

    /**
     * 退休时间
     */
    private LocalDateTime txdq;

    /**
     * 挂职组织
     */
    private String gzzz;

    /**
     * 挂职部门
     */
    private String gzbm;

    /**
     * 组织标识
     */
    private String ormorgid;

    /**
     * 组织
     */
    private String ormorgname;

    /**
     * 部门标识
     */
    private String ormorgsectorid;

    /**
     * 部门
     */
    private String ormorgsectorname;

    /**
     * 岗位状态
     */
    private String gwzt;

    /**
     * 记录所属
     */
    private String jlss;

    /**
     * 记录管理编号
     */
    private String jlglbh;

    /**
     * 记录审批状态
     */
    private String jlspzt;

    /**
     * 记录操作者
     */
    private String jlczz;

    private Integer gly;

    private Integer gly2;

    /**
     * 档案出生日期
     */
    private LocalDateTime dacsrq;

    /**
     * 人才序列标识
     */
    private String pcmrcxlid;

    /**
     * 身故原因
     */
    private String sgyy;

    /**
     * 通讯地址
     */
    private String postaladdress;

    /**
     * 到建筑系统时间
     */
    private LocalDateTime tozjdate;

    /**
     * 人员信息标识
     */
    private String pimpersonid2;

    /**
     * 人员信息标识
     */
    private String pimpersonid3;

    /**
     * 黑名单原因
     */
    private String blacklistreasons;

    /**
     * 市标识
     */
    private String pimcityid;

    /**
     * 实习/试用期限
     */
    private String duration;

    /**
     * 员工编号启用时间
     */
    private LocalDateTime ygbhqysj;

    /**
     * 实际退休时间
     */
    private LocalDateTime sjtxrq;

    private Integer isleaderteam;

    /**
     * 职级日期
     */
    private LocalDateTime rankrq;

    /**
     * 职务日期
     */
    private LocalDateTime zwrq;

    /**
     * 业务导师
     */
    private String pimpersonname3;

    /**
     * 思想导师
     */
    private String pimpersonname2;

    /**
     * XX届应届生
     */
    private String yjsnf;

    /**
     * 异动状态
     */
    private String ydzt;

    /**
     * 调动日期
     */
    private LocalDateTime transferdate;

    /**
     * 离职日期
     */
    private LocalDateTime leavedate;

    /**
     * 试用期到期时间（停用）
     */
    private LocalDateTime syqdqsj;

    /**
     * 审批的养老金额
     */
    private Double spdylje;

    /**
     * 退休地
     */
    private String retiplace;

    /**
     * 专业序列类型标识
     */
    private String pimmajorsetypeid;

    /**
     * 人才序列类型
     */
    private String rcxllx;

    /**
     * 家庭联系人
     */
    private String jtlxr;

    /**
     * 家庭联系人电话
     */
    private String jtlxrdh;

    /**
     * 原员工编号
     */
    private String yygbh;

    /**
     * 家庭联系人ID
     */
    private String jtlxrid;

    private Integer sfnbfp;

    /**
     * 岗位开始日期
     */
    private LocalDateTime gwksrq;

    /**
     * 最高学历
     */
    private String higheducation;

    /**
     * 第一学历
     */
    private String firsteducation;

    /**
     * 最高职称
     */
    private String hightitle;

    /**
     * 执业证书
     */
    private String certtificate;

    /**
     * 健康状况
     */
    private String jkzk;

    /**
     * 户籍地址
     */
    private String hjdz;

    /**
     * 任职时间
     */
    private LocalDateTime rzsj;

    private Integer khcjtx;

    /**
     * 轮岗年限颜色_干部花名册
     */
    private String lgnxColor;

    /**
     * 试岗开始日期_干部花名册
     */
    private LocalDateTime sgksrq;

    /**
     * 试岗结束日期_干部花名册
     */
    private LocalDateTime sgjsrq;

    /**
     * 第一学历毕业时间_干部花名册
     */
    private LocalDateTime dyxlbysj;

    /**
     * 上一次职级日期_干部花名册
     */
    private LocalDateTime syczjrq;

    /**
     * 惩罚影响结束日期_干部花名册
     */
    private LocalDateTime cfyxjsrq;

    /**
     * 任职年龄到期(年)_干部花名册（作废）
     */
    private String rznldq;

    /**
     * 轮岗开始时间_干部花名册
     */
    private LocalDateTime lgkssj;

    /**
     * 岗位到期(月)_干部花名册
     */
    private String postexpiration;

    /**
     * 轮岗年限_干部花名册
     */
    private String lgnx;

    /**
     * 岗位_干部花名册
     */
    private String ormpostname;

    /**
     * 第一学历毕业院校_干部花名册
     */
    private String dyxlbyyx;

    /**
     * 第一学历所属专业_干部花名册
     */
    private String dyxlsszy;

    /**
     * 后取学历所学专业_干部花名册
     */
    private String hqxlsxzy;

    /**
     * 后取学历毕业院校_干部花名册
     */
    private String hqxlbyyx;

    /**
     * 执业资格_干部花名册
     */
    private String zyzg;

    /**
     * 兼职任职_干部花名册（作废）
     */
    private String jzrz;

    private Integer age;

    private Integer zjnx;

    /**
     * 职务年限_干部花名册
     */
    private String zwnx;

    private Integer rznx;

    /**
     * 试岗状态_干部花名册
     */
    private String zt;

    /**
     * 任职年龄到期颜色_干部花名册（作废）
     */
    private String rznldqColor;

    /**
     * 任职年龄到期时间
     */
    private LocalDateTime rzdq;

    /**
     * 考核成绩(近三年)
     */
    private String khcj;

    private Integer numcode;

    /**
     * 部门组织类型
     */
    private String orgtype;

    /**
     * 工作状态
     */
    private String workstate;

    /**
     * 档案学历
     */
    private String daxl;

    /**
     * 档案入党时间
     */
    private LocalDateTime dardsj;

    /**
     * 档案参加工作时间
     */
    private LocalDateTime dacjgzsj;

    /**
     * 门户系统用户id
     */
    private String portaluserid;

    private Integer superuser;

    /**
     * 操作
     */
    private String cz;

    /**
     * 见习生员工转正记录引用明细标识
     */
    private String pcmjxsygzzjlmxid;

    /**
     * 身份证
     */
    private String sfz;

    /**
     * 员工编号更新时间戳
     */
    private LocalDateTime ygbhUpdateDate;

    /**
     * 员工状态更新时间戳
     */
    private LocalDateTime ygztUpdateDate;

    /**
     * 员工姓名更新时间戳
     */
    private LocalDateTime nameUpdateDate;

    private Integer isdirector;

    private Integer issupervisor;

    private Integer ischairman;

    /**
     * 备份姓名
     */
    private String tmpPimpersonname;

    /**
     * 备份工号
     */
    private String tmpYgbh;

    /**
     * 备份证件号
     */
    private String tmpZjhm;

    /**
     * 备份联系电话
     */
    private String tmpLxdh;

    /**
     * 备份邮箱
     */
    private String tmpDzyx;


}
