package com.zeroone.star.common.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

@Getter
@Setter
@TableName("t_personstatemgr")
public class TPersonStateMgr implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 建立人
     */
    private String creatMan;

    /**
     * PERSONSTATEMGRNAME
     * 员工状态管理名称
     */
    private String personStateMgrName;

    /**
     * PERSONSTATEMGRID
     * 员工状态管理标识
     */
    private String personStateMgrId;

    /**
     * CREATEDATE
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createDate;

    /**
     * UPDATEMAN
     * 更新人
     */
    private String updateMan;

    /**
     * UPDATEDATE
     * 更新时间
     */
    @TableField(fill = FieldFill.INSERT_UPDATE)
    private LocalDateTime updateDate;

    /**
     * PERSONSTATECODE
     * 状态编码
     */
    private String personStateCode;

    /**
     * ORDERNO
     */
    private Integer orderNo;

}
