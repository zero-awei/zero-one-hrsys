package com.zeroone.star.project.dto;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 描述：分页数据实体
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
public class PageDTO<T> implements Serializable {
    /**
     * 当前页码
     */
    @ApiModelProperty(value = "当前页码", example = "1")
    protected Long pageIndex;

    /**
     * 每页显示最大数据条数
     */
    @ApiModelProperty(value = "每页显示最大数据条数", example = "10")
    protected Long pageSize;

    /**
     * 数据的总条数
     */
    @ApiModelProperty(value = "总条数", example = "100000")
    protected Long total;

    /**
     * 数据的总页数
     */
    @ApiModelProperty(value = "总页数", example = "100")
    protected Long pages;

    /**
     * 当前页数据列表
     */
    @ApiModelProperty(value = "当前页数据列表")
    protected List<T> rows;

    /**
     * 静态构建方法，将分页插件的page对象转换成当前pageDto对象
     * @param page 分页插件的page对象
     * @param <T>  列表元素类型模板一般是DO
     * @return 返回分页数据对象
     */
    public static <T> PageDTO<T> create(Page<T> page) {
        PageDTO<T> pageResult = new PageDTO<>();
        pageResult.setTotal(page.getTotal());
        pageResult.setRows(page.getRecords());
        pageResult.setPageIndex(page.getCurrent());
        pageResult.setPageSize(page.getSize());
        pageResult.setPages(page.getPages());
        return pageResult;
    }

    /**
     * 静态构建方法，将分页插件的page对象转换成当前pageDto对象
     * @param page     分页插件的page对象
     * @param callback 数据转换回调函数
     * @param <T>      列表元素类型模板一般是DTO
     * @param <D>      数据表数据类型模板一般是DO
     * @return 返回分页数据对象
     */
    public static <T, D> PageDTO<T> create(Page<D> page, DataTransCallBack<T, D> callback) {
        //初始化分页信息
        PageDTO<T> pageResult = new PageDTO<>();
        pageResult.setTotal(page.getTotal());
        pageResult.setPageIndex(page.getCurrent());
        pageResult.setPageSize(page.getSize());
        pageResult.setPages(page.getPages());
        //转换数据
        List<D> records = page.getRecords();
        if (records != null && !records.isEmpty()) {
            List<T> rows = new ArrayList<>();
            for (D sub : records) {
                try {
                    T t = callback.executeTrans(sub);
                    rows.add(t);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
            pageResult.setRows(rows);
        }
        return pageResult;
    }

    /**
     * 静态构建方法，将分页插件的page对象转换成当前pageDto对象
     * @param page   分页插件的page对象
     * @param tClass 分页数据列表元素类型
     * @param <T>    列表元素类型模板一般是DTO
     * @param <D>    数据表数据类型模板一般是DO
     * @return 返回分页数据对象
     */
    public static <T, D> PageDTO<T> create(Page<D> page, Class<T> tClass) {
        //使用BeanUtil进行属性复制
        DataTransCallBack<T, D> defaultTransCallBack = src -> {
            try {
                T t = tClass.newInstance();
                BeanUtil.copyProperties(src, t);
                return t;
            } catch (InstantiationException | IllegalAccessException e) {
                throw new RuntimeException(e);
            }
        };
        //获取转换方法创建PageDTO对象
        return create(page, defaultTransCallBack);
    }
}
