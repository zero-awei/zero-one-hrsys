package com.zeroone.star.common.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/**
 * <p>
 * 岗位性质
 * </p>
 *
 * @author letian
 * @since 2023-05-31
 */
@Getter
@Setter
@TableName("zo_post_nature")
public class ZoPostNature implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 岗位性质ID
     */
    private String id;

    /**
     * 岗位性质
     */
    private String postNature;

    /**
     * 岗位性质状态码
     */
    private String postNatureCode;


}
