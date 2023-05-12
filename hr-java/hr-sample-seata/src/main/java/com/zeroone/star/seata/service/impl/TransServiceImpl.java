package com.zeroone.star.seata.service.impl;

import com.zeroone.star.seata.service.TransService;
import io.seata.spring.annotation.GlobalTransactional;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.Random;

/**
 * <p>
 * 描述：测试事务服务实现类
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Service
@GlobalTransactional
public class TransServiceImpl implements TransService {
    private final Random random = new Random();

    @Resource
    JdbcTemplate jdbcTemplate;

    @Override
    public int saveData() {
        //随机执行数据更新
        if (random.nextBoolean()) {
            String sql = "UPDATE `sample` SET `name`='小风2', `sex`='男' WHERE `id`=2";
            return jdbcTemplate.update(sql);
        }
        return 0;
    }
}
