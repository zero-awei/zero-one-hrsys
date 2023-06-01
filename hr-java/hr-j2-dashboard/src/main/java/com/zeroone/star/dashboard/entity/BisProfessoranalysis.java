package com.zeroone.star.dashboard.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 职称信息表
 * </p>
 *
 * @author wxs
 * @since 2023-05-23
 */
@Getter
@Setter
@TableName("bis_professoranalysis_t")
public class BisProfessoranalysis implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 职称表ID，主键，供其他表做外键
     */
    private String professoranalysisId;

    /**
     * 职称名称
     */
    private String professoranalysisName;

    /**
     * 证书编号
     */
    private String credentialsNum;

    /**
     * 职称等级
     */
    private String professorGrades;

    /**
     * 职称类型
     */
    private String professorType;

    /**
     * 专业类别
     */
    private String professionalCategory;

    /**
     * 职称获取时间
     */
    private LocalDateTime professorDate;

    /**
     * 员工基本信息表ID，同员工ID
     */
    private String employeeanalysisId;

    /**
     * 员工姓名
     */
    private String employeename;

    /**
     * 员工编号
     */
    private String employeeid;

    /**
     * 组织名称
     */
    private String organizationName;

    /**
     * 组织ID
     */
    private String organizationId;

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
     * 专业序列
     */
    private String major;


}
