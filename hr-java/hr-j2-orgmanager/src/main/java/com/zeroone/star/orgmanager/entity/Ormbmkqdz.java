package com.zeroone.star.orgmanager.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 部门地址维护
 * </p>
 *
 * @author rqs
 * @since 2023-05-19
 */
@Getter
@Setter
@TableName("t_ormbmkqdz")
public class Ormbmkqdz implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 部门地址维护标识
     */
    @TableId(value = "ORMBMKQDZID")
    private String ormbmkqdzid;

    /**
     * 部门地址
     */
    @TableField(value = "ORMBMKQDZNAME")
    private String ormbmkqdzname;

    /**
     * 建立时间
     */
    @TableField(value = "CREATEDATE")
    private LocalDateTime createdate;

    /**
     * 建立人
     */
    @TableField(value = "CREATEMAN")
    private String createman;

    /**
     * 更新人
     */
    @TableField(value = "UPDATEMAN")
    private String updateman;

    /**
     * 更新时间
     */
    @TableField(value = "UPDATEDATE")
    private LocalDateTime updatedate;

    @TableField(value = "XH")
    private Integer xh;

    /**
     * 部门ID
     */
    @TableField(value = "ORMORGSECTORID")
    private String ormorgsectorid;

    /**
     * 默认考勤地址
     */
    @TableField(value = "SFMRKQDZ")
    private String sfmrkqdz;

    /**
     * 组织地址ID
     */
    @TableField(value = "ORMORGDZID")
    private String ormorgdzid;

    @TableField(value = "`RANGE`")
    private Integer range;

    /**
     * 经度
     */
    @TableField(value = "LNG")
    private Double lng;

    /**
     * 纬度
     */
    @TableField(value = "LAT")
    private Double lat;

    /**
     * 考勤范围
     */
    @TableField(value = "ATTENDANCERANGE")
    private Integer attendancerange;


}
