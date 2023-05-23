package com.zeroone.star.common.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author rqs
 * @since 2023-05-23
 */
@Getter
@Setter
@TableName("t_pimzzmm")
public class Zzmm implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 政治面貌ID
     */
    private String id;

    /**
     * 政治面貌名称
     */
    private String name;

    /**
     * 政治面貌代号
     */
    private String code;

    /**
     * 是否有效 (0无效, 1有效)
     */
    private Boolean validity;


}
