package com.zeroone.star.mq;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.cloud.stream.annotation.EnableBinding;
import org.springframework.cloud.stream.messaging.Source;

/**
 * <p>
 * 描述：程序入口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@SpringBootApplication
@EnableDiscoveryClient
@EnableBinding(Source.class)
public class MqApplication {
    public static void main(String[] args) {
        SpringApplication.run(MqApplication.class,args);
    }
}
