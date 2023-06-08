package com.zeroone.star.sysmanager;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;

/**
 * <p>
 * 描述：系统服务器启动入口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author naturezh
 * @version 1.0.0
 */
@SpringBootApplication
@EnableDiscoveryClient
public class SysmanagerApplication {

    public static void main(String[] args) {
        SpringApplication.run(SysmanagerApplication.class, args);
    }

}
