package com.zeroone.star.common.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 岗位库
 * </p>
 *
 * @author letian
 * @since 2023-05-21
 */
@Getter
@Setter
@TableName("t_ormpostlib")
public class Ormpostlib implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 岗位标识
     */
    private String ormpostlibid;

    /**
     * 建立时间
     */
    private LocalDateTime createdate;

    /**
     * 建立人
     */
    private String createman;

    /**
     * 岗位名称
     */
    private String ormpostlibname;

    /**
     * 更新时间
     */
    private LocalDateTime updatedate;

    /**
     * 更新人
     */
    private String updateman;

    /**
     * 岗位职责说明
     */
    private String jobdesc;

    /**
     * 岗位类型
     */
    private String gwtype;

    /**
     * 岗位标签
     */
    private String gwflag;

    private Integer mustexcyear;

    private Integer sugexcyear;

    /**
     * 是否保密岗
     */
    private String isconfidential;

    /**
     * 岗位性质
     */
    private String postnature;


}
