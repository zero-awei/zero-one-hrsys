package com.zeroone.star.orgmanager.entity;

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
 * @author wxs
 * @since 2023-05-19
 */

@Getter
@Setter
@TableName("t_ormbmkqdz")
public class TOrmbmkqdz implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 部门地址维护标识
     */
    private String ormbmkqdzid;

    /**
     * 部门地址
     */
    private String ormbmkqdzname;

    /**
     * 建立时间
     */
    private LocalDateTime createdate;

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

    private Integer xh;

    /**
     * 部门ID
     */
    private String ormorgsectorid;

    /**
     * 默认考勤地址
     */
    private String sfmrkqdz;

    /**
     * 组织地址ID
     */
    private String ormorgdzid;

    private Integer range;

    /**
     * 经度
     */
    private Double lng;

    /**
     * 纬度
     */
    private Double lat;

    /**
     * 考勤范围
     */
    private Integer attendancerange;


}
