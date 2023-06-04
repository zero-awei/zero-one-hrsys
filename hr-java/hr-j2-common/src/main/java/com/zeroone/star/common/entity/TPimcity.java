package com.zeroone.star.common.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 市
 * </p>
 *
 * @author 浅墨
 * @since 2023-06-04
 */
@Getter
@Setter
@TableName("t_pimcity")
public class TPimcity implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 市标识
     */
    private String pimcityid;

    /**
     * 市名称
     */
    private String pimcityname;

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

    private String type;

    /**
     * 类型
     */
    private String protype;


}
