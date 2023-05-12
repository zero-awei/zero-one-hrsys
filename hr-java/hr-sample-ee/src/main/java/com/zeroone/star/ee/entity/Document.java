package com.zeroone.star.ee.entity;

import cn.easyes.annotation.IndexName;
import lombok.Data;

/**
 * <p>
 * 描述：ES数据模型
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Data
@IndexName("document")
public class Document {
    /**
     * es中的唯一id
     */
    private String id;

    /**
     * 文档标题
     */
    private String title;
    /**
     * 文档内容
     */
    private String content;
}
