package com.zeroone.star.dashboard.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 员工基本信息分析表
 * </p>
 *
 * @author letian
 * @since 2023-05-21
 */
@Getter
@Setter
@TableName("bis_employeeanalysis_t")
public class BisEmployeeanalysis implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 表ID，主键，供其他表做外键
     */
    private String employeeanalysisId;

    /**
     * 组织ID
     */
    private String organizationId;

    /**
     * 组织名称
     */
    private String organizationName;

    /**
     * 员工编号
     */
    private String employeeid;

    /**
     * 员工姓名
     */
    private String employeename;

    /**
     * 员工类型
     */
    private String employeetype;

    /**
     * 身份证号码
     */
    private String idnumber;

    /**
     * 专业序列
     */
    private String major;

    /**
     * 源系统行ID，追溯字段，默认=本表ID
     */
    private String sourceLineId;

    /**
     * 学历（最高学历），约定：
TECHSECSCH/中专及以下
JUNIOR/大专
UNDERGRAD/本科
MD/硕士
DR/博士

     */
    private String highestdegree;

    private LocalDateTime creationDate;

    private Integer createdBy;

    private Integer lastUpdatedBy;

    private LocalDateTime lastUpdateDate;

    private Integer lastUpdateLogin;

    private String attributeCategory;

    private String attribute1;

    private String attribute2;

    private String attribute3;

    private String attribute4;

    private String attribute5;

    private String attribute6;

    private String attribute7;

    private String attribute8;

    private String attribute9;

    private String attribute10;

    private String attribute11;

    private String attribute12;

    private String attribute13;

    private String attribute14;

    private String attribute15;

    /**
     * 组织类型
     */
    private String ormtype;


}
