package com.zeroone.star.common.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 岗位类型对照表
 * </p>
 *
 * @author letian
 * @since 2023-05-21
 */
@Getter
@Setter
@TableName("t_pimgwtype")
public class Pimgwtype implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 岗位类型对照表标识
     */
    private String pimgwtypeid;

    /**
     * 岗位类型对照表名称
     */
    private String pimgwtypename;

    private Integer enable;

    /**
     * 建立人
     */
    private String createman;

    /**
     * 建立时间
     */
    private LocalDateTime createdate;

    /**
     * 更新人
     */
    private String updateman;

    /**
     * 更新时间
     */
    private LocalDateTime updatedate;

    /**
     * 岗位类型
     */
    private String gwlx;

    private Integer ordervalue;


}
