package com.zeroone.star.login.utils;

import lombok.extern.slf4j.Slf4j;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Component;

import javax.annotation.Resource;
import java.util.concurrent.TimeUnit;

/**
 * @author 风月
 * @date 2023/5/15 21:03
 */
@Component
@Slf4j
public class RedisUtils {
    @Resource
    private RedisTemplate<String, Object> redisTemplate;

    /***
     * redis中add命令
     * @param key
     * @param value
     * @param timeout
     * @param timeUnit
     * @return 失败返回-1
     */
    public int add(String key, Object value, Long timeout, TimeUnit timeUnit) {
        try {
            if (Boolean.FALSE.equals(redisTemplate.opsForValue().setIfAbsent(key, value, timeout, timeUnit))) {
                // 添加失败
                return -1;
            }

        } catch (Exception e) {
            log.error("RedisUtils#add fail! e:{" + e.getStackTrace().toString() + "}");
            return -1;
        }
        return 0;
    }

    /***
     * 获得key
     * @param key
     * @return
     */
    public Object get(String key) {
        Object value = null;
        try {
            value = redisTemplate.opsForValue().get(key);
        } catch (Exception e) {
            log.error("RedisUtils#get fail! e:{" + e.getStackTrace().toString() + "}");
        }
        return value;
    }
    /***
     *
     * 判断key是否存在
     * @param key
     * @return
     */
    public boolean isExist(String key) {
        if (get(key) != null) {
            return true;
        }
        return false;
    }

    /**
     * 删除key
     * @param key
     * @return
     */
    public int del(String key) {
        try {
            if (Boolean.FALSE.equals(redisTemplate.delete(key))) {
                return -1;
            }
        } catch (Exception e) {
            log.error("RedisUtils#del fail! e:{" + e.getStackTrace().toString() + "}");
            return -1;
        }

        return 0;
    }

}
