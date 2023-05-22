package com.zeroone.star.user.config;


import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

//扫描自定义组件
@Configuration
@ComponentScan({
        "com.zeroone.star.project.components.fastdfs",
})
public class ComponentInit {
}
