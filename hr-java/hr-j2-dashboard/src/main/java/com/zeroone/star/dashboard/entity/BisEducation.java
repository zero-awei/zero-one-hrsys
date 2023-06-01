package com.zeroone.star.dashboard.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 学历代码表
 * </p>
 *
 * @author rqs
 * @since 2023-05-18
 */
@Getter
@Setter
@TableName("bis_education_t")
public class BisEducation implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 学历代码表项ID,  KEY
     */
    private String educationid;

    /**
     * 学历,  VALUE
     */
    private String educationname;

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


}
