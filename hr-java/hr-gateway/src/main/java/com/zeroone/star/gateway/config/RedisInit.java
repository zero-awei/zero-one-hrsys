package com.zeroone.star.gateway.config;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

/**
 * <p>
 * 描述：Redis初始化
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
@Configuration
@ComponentScan({"com.zeroone.star.project.config.redis","com.zeroone.star.project.utils.redis"})
public class RedisInit {
}
