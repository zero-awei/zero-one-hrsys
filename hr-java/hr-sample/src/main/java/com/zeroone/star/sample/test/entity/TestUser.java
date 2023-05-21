package com.zeroone.star.sample.test.entity;

import lombok.Builder;
import lombok.Data;

/**
 * <p>
 * 描述：测试用户类
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Data
@Builder
public class TestUser {
    private Integer id;
    private String name;
    private String phone;
}
