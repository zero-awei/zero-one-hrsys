package com.zeroone.star.orgmanager;

import org.mybatis.spring.annotation.MapperScan;
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
 * @author zh
 * @version 1.0.0
 */
@SpringBootApplication
@EnableDiscoveryClient
@MapperScan("com.zeroone.star.orgmanager.mapper")
public class OrgManagerApplication {

    public static void main(String[] args) {
        SpringApplication.run(OrgManagerApplication.class, args);
    }

}
