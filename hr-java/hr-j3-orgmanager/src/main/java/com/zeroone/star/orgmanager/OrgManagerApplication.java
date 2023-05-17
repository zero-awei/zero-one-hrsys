package com.zeroone.star.orgmanager;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;

/**
 * <p>
 * 描述：服务器启动入口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 浅墨
 * @version 1.0.0
 */
@SpringBootApplication
@EnableDiscoveryClient
public class OrgManagerApplication {

    public static void main(String[] args) {
        SpringApplication.run(OrgManagerApplication.class, args);
    }

}
