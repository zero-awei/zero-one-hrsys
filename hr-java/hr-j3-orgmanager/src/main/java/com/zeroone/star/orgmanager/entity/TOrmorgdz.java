package com.zeroone.star.orgmanager.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 组织地址维护
 * </p>
 *
 * @author wh
 * @since 2023-05-31
 */
@Getter
@Setter
@TableName("t_ormorgdz")
public class TOrmorgdz implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 组织地址维护标识
     */
    private String ormorgdzid;

    /**
     * 组织地址
     */
    private String ormorgdzname;

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
     * 更新人
     */
    private String updateman;

    /**
     * 组织ID
     */
    private String ormorgid;

    private Integer xh;

    /**
     * 默认组织地址
     */
    private String deforgaddress;


}
