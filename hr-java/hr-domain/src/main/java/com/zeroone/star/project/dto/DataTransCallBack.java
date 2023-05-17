package com.zeroone.star.project.dto;

/**
 * <p>
 * 描述：数据转换回调接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @param <T> 目标对象类型
 * @param <D> 来源对象类型
 * @author 阿伟学长
 * @version 1.0.0
 */
public interface DataTransCallBack<T, D> {
    /**
     * 执行转换
     * @param src 待转换对象
     * @return 转换目标对象
     */
    T executeTrans(D src);
}
