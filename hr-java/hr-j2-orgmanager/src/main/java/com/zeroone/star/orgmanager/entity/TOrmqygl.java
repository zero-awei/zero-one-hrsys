package com.zeroone.star.orgmanager.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 补贴标准
 * </p>
 *
 * @author wxs
 * @since 2023-05-19
 */
@Getter
@Setter
@TableName("t_ormqygl")
public class TOrmqygl implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 区域名称
     */
    private String ormqyglname;

    /**
     * 区域标识
     */
    private String ormqyglid;

    /**
     * 更新人
     */
    private String updateman;

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
     * 备注说明
     */
    private String bzsm;

    private Integer xh;

    /**
     * 组织ID
     */
    private String ormorgid;


}
