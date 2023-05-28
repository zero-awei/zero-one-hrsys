package com.zeroone.star.orgmanager.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;

import lombok.Data;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 职务管理
 * </p>
 *
 * @author loop
 * @since 2023-05-27
 */
@Data
@TableName("t_ormduty")
public class TOrmduty implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 职务标识
     */
    private String ormdutyid;

    /**
     * 更新人
     */
    private String updateman;

    /**
     * 更新时间
     */
    private LocalDateTime updatedate;

    /**
     * 建立人
     */
    private String createman;

    /**
     * 建立时间
     */
    private LocalDateTime createdate;

    /**
     * 职务名称
     */
    private String ormdutyname;

    /**
     * 序号
     */
    private Integer xh;

    /**
     * 层级
     */
    private String zwlb;

    /**
     * 职务编码
     */
    private String fglx;

    /**
     * 对应职级
     */
    private String dyzj;

    private Integer nx;

    private Integer bxjlnx;

    /**
     * 职务级别
     */
    private String zwjb;


}
