package com.zeroone.star.dashboard.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;


/**
 * <p>
 * 
 * </p>
 *
 * @author wxs
 * @since 2023-06-01
 */
@Getter
@Setter
@TableName("bis_pimoutput_t")
public class BisPimoutputT implements Serializable {

    private static final long serialVersionUID = 1L;

    private String pimoutputid;

    private String year;

    private String monthly;

    private Integer output;

    private String ormorgid;

    private String ormorgname;

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

    private LocalDateTime outdate;


}
