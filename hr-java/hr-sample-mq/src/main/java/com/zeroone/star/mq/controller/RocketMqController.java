package com.zeroone.star.mq.controller;

import com.zeroone.star.mq.components.RocketMqSourceComponent;
import com.zeroone.star.project.dto.notify.SampleNotifyDTO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.AllArgsConstructor;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * <p>
 * 描述：消息发布控制器
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@RestController
@Api(tags = "rocketmq使用示例")
@AllArgsConstructor
public class RocketMqController {
    private final RocketMqSourceComponent component;

    @ApiOperation(value = "发布消息")
    @PostMapping("publish")
    public JsonVO<String> testSend(SampleNotifyDTO dto){
        component.publishNotify(dto);
        return JsonVO.success("发送成功");
    }
}
