package com.zeroone.star.orgmanager.entity;

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
 * @author rqs
 * @since 2023-05-19
 */
@Getter
@Setter
@TableName("t_ormorginfo")
public class Ormorginfo implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 组织ID
     */
    private String ormorginfoid;

    /**
     * 组织名称
     */
    private String ormorginfoname;

    /**
     * 建立时间
     */
    private LocalDateTime createdate;

    /**
     * 建立人
     */
    private String createman;

    /**
     * 更新时间
     */
    private LocalDateTime updatedate;

    /**
     * 更新人
     */
    private String updateman;

    /**
     * 组织编码
     */
    private String orgcode;

    /**
     * 组织简称
     */
    private String shortname;

    /**
     * 组织排序编号
     */
    private String ordernum;

    /**
     * 组织类型
     */
    private String orgtype;

    /**
     * 组织类型释义
     */
    private String orgtypename;

    /**
     * 所属OU的组织ID
     */
    private String ouid;

    /**
     * 所属区域
     */
    private String belongregion;

    /**
     * 补贴标准
     */
    private String substandard;

    /**
     * 上级组织ID
     */
    private String porgid;

    /**
     * ERP组织ID
     */
    private String ormerporgid;

    /**
     * 启停标识
     */
    private String startstopsign;

    /**
     * 岗位
     */
    private String postinfo;

    /**
     * 上级部门ID
     */
    private String porgsectorid;


}
