package com.zeroone.star.orgmanager.entity;

import com.alibaba.excel.annotation.ExcelProperty;
import com.baomidou.mybatisplus.annotation.TableName;

import java.io.Serializable;
import java.time.LocalDateTime;

import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 职务管理
 * </p>
 *
 * @author H
 * @since 2023-05-25
 */
@Getter
@Setter
@TableName("t_ormduty")
public class TOrmduty implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 职务标识
     */
    @ExcelProperty(value = "编号", index = 0)
    private String ormdutyid;

    /**
     * 更新人
     */
    @ExcelProperty(value = "编号", index = 1)
    private String updateman;

    /**
     * 更新时间
     */
    @ExcelProperty(value = "编号", index = 2)
    private LocalDateTime updatedate;

    /**
     * 建立人
     */
    @ExcelProperty(value = "编号", index = 3)
    private String createman;

    /**
     * 建立时间
     */
    @ExcelProperty(value = "编号", index = 4)
    private LocalDateTime createdate;

    /**
     * 职务
     */
    @ExcelProperty(value = "编号", index = 5)
    private String ormdutyname;

    @ExcelProperty(value = "编号", index = 6)
    private Integer xh;

    /**
     * 层级
     */
    @ExcelProperty(value = "编号", index = 7)
    private String zwlb;

    /**
     * 职务编码
     */
    @ExcelProperty(value = "编号", index = 8)
    private String fglx;

    /**
     * 对应职级
     */
    @ExcelProperty(value = "编号", index = 9)
    private String dyzj;
    @ExcelProperty(value = "编号", index = 10)
    private Integer nx;
    @ExcelProperty(value = "编号", index = 11)
    private Integer bxjlnx;

    /**
     * 职务级别
     */
    @ExcelProperty(value = "编号", index = 12)
    private String zwjb;


}
