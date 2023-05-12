package com.zeroone.star.seata.controller;

import com.zeroone.star.seata.service.TransService;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：测试远程事务控制器
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@RestController
@RequestMapping("seata")
public class SampleController {
    @Resource
    TransService service;

    @GetMapping("test-trans")
    public Integer testTrans() {
        return service.saveData();
    }
}
