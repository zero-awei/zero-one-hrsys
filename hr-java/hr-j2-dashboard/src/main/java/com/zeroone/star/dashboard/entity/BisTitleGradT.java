package com.zeroone.star.dashboard.entity;


import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

@TableName("bis_titlegrad_t")
@Getter
@Setter
public class BisTitleGradT implements Serializable {
    /**
     * TITLEGRADEID
     * 职称等级代码项ID
     */
    private String titleGradeId;

    /**
     * TITLEGRADEVALUE
     * 职称等级代码 ex:5  10  15  20
     */
    private String titleGradeValue;

    /**
     * TITLEGRADENAME
     * 职称等级  ex：中级 初级 高级  正高级
     */
    private String titleGradeName;

    /**
     * ORDERVALUE
     */
    private Integer orderValue;

    /**
     * CREATION_DATE
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime creationDate;

    /**
     * CREATED_BY
     */
    private Integer createdBy;

    /**
     * LAST_UPDATED_BY
     */
    private Integer lastUpdatedBy;

    /**
     * LAST_UPDATE_DATE
     */
    @TableField(fill = FieldFill.INSERT_UPDATE)
    private LocalDateTime lastUpdateDate;

    /**
     * LAST_UPDATE_LOGIN
     */
    private Integer lastUpdateLogin;

    /**
     * ATTRIBUTE_CATEGORY
     */
    private String attributeCategory;

    /**
     * ATTRIBUTE1
     */
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
