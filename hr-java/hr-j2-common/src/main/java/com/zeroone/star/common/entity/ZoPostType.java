package com.zeroone.star.common.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/**
 * <p>
 * 岗位分类
 * </p>
 *
 * @author letian
 * @since 2023-05-31
 */
@Getter
@Setter
@TableName("zo_post_type")
public class ZoPostType implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 岗位分类ID
     */
    private String id;

    /**
     * 岗位分类
     */
    private String postType;

    /**
     * 岗位分类状态码
     */
    private String postTypeCode;


}
