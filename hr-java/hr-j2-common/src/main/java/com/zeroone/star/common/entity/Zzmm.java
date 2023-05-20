package com.zeroone.star.common.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 人员信息
 * </p>
 *
 * @author rqs
 * @since 2023-05-17
 */
@Getter
@Setter
@TableName("t_pimperson")
public class Zzmm implements Serializable {
    private static final long serialVersionUID = 1L;

    @TableId(value = "ZZMMID", type = IdType.AUTO)
    private Integer zzmmid;

    private String zzmmname;

}
