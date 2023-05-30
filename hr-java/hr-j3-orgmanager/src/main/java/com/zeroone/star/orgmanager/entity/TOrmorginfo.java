package com.zeroone.star.orgmanager.entity;

import com.alibaba.excel.annotation.ExcelProperty;
import com.baomidou.mybatisplus.annotation.TableName;

import java.io.Serializable;
import java.time.LocalDateTime;

import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 组织信息
 * </p>
 *
 * @author H
 * @since 2023-05-30
 */
@Getter
@Setter
@TableName("t_ormorginfo")
public class TOrmorginfo implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 组织ID
     */
    @ExcelProperty(value = "编号", index = 0)
    private String ormorginfoid;

    /**
     * 组织名称
     */
    @ExcelProperty(value = "编号", index = 1)
    private String ormorginfoname;

    /**
     * 建立时间
     */
    @ExcelProperty(value = "编号", index = 2)
    private LocalDateTime createdate;

    /**
     * 建立人
     */
    @ExcelProperty(value = "编号", index = 3)
    private String createman;

    /**
     * 更新时间
     */
    @ExcelProperty(value = "编号", index = 4)
    private LocalDateTime updatedate;

    /**
     * 更新人
     */
    @ExcelProperty(value = "编号", index = 5)
    private String updateman;

    /**
     * 组织编码
     */
    @ExcelProperty(value = "编号", index = 6)
    private String orgcode;

    /**
     * 组织简称
     */
    @ExcelProperty(value = "编号", index = 7)
    private String shortname;

    /**
     * 组织排序编号
     */
    @ExcelProperty(value = "编号", index = 8)
    private String ordernum;

    /**
     * 组织类型
     */
    @ExcelProperty(value = "编号", index = 9)
    private String orgtype;

    /**
     * 组织类型释义
     */
    @ExcelProperty(value = "编号", index = 10)
    private String orgtypename;

    /**
     * 所属OU的组织ID
     */
    @ExcelProperty(value = "编号", index = 11)
    private String ouid;

    /**
     * 所属区域
     */
    @ExcelProperty(value = "编号", index = 12)
    private String belongregion;

    /**
     * 补贴标准
     */
    @ExcelProperty(value = "编号", index = 13)
    private String substandard;

    /**
     * 上级组织ID
     */
    @ExcelProperty(value = "编号", index = 14)
    private String porgid;

    /**
     * ERP组织ID
     */
    @ExcelProperty(value = "编号", index = 15)
    private String ormerporgid;

    /**
     * 启停标识
     */
    @ExcelProperty(value = "编号", index = 16)
    private String startstopsign;

    /**
     * 岗位
     */
    @ExcelProperty(value = "编号", index = 17)
    private String postinfo;

    /**
     * 上级部门ID
     */
    @ExcelProperty(value = "编号", index = 18)
    private String porgsectorid;


}
