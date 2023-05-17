package com.zeroone.star.project.dto.notify;

import lombok.Data;

/**
 * <p>
 * 描述：示例通知数据对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
@Data
public class SampleNotifyDTO {
    /**
     * 客户端编号
     */
    private String clientId;

    /**
     * 通知消息内容
     */
    private String message;
}
