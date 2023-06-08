package com.zeroone.star.project.vo;

import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;

/**
 * <p>
 * 描述：前后端数据对接数据对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
public class JsonVO<T> implements Serializable {
    /**
     * 状态码
     */
    @ApiModelProperty(value = "状态码", example = "10000")
    private Integer code;

    /**
     * 提示消息
     */
    @ApiModelProperty(value = "提示消息", example = "提示消息内容")
    private String message;

    /**
     * 数据对象
     */
    @ApiModelProperty(value = "数据对象")
    private T data;

    /**
     * 通过结果枚举设置状态码和提示消息
     * @param resultStatus 结果状态枚举
     */
    private void setStatus(ResultStatus resultStatus) {
        this.setMessage(resultStatus.getMessage());
        this.setCode(resultStatus.getCode());
    }

    /**
     * 静态构建方式
     * @param data         获取的数据
     * @param resultStatus 提示信息
     * @param <T>          JsonVO嵌套元素类型
     * @return 返回创建的JSON VO对象
     */
    public static <T> JsonVO<T> create(T data, ResultStatus resultStatus) {
        JsonVO<T> result = new JsonVO<>();
        result.setStatus(resultStatus);
        result.setData(data);
        return result;
    }

    /**
     * 静态构建方式
     * @param data    获取的数据
     * @param code    状态码
     * @param message 提示信息
     * @param <T>     JsonVO嵌套元素类型
     * @return 返回创建的JSON VO对象
     */
    public static <T> JsonVO<T> create(T data, int code, String message) {
        JsonVO<T> result = new JsonVO<>();
        result.setCode(code);
        result.setMessage(message);
        result.setData(data);
        return result;
    }

    /**
     * 静态构建处理成功数据对象
     * @param data 数据对象
     * @param <T>  JsonVO嵌套元素类型
     * @return 返回创建的JSON VO对象
     */
    public static <T> JsonVO<T> success(T data) {
        return create(data, ResultStatus.SUCCESS);
    }

    /**
     * 静态构建处理失败数据对象
     * @param data 数据对象
     * @param <T>  JsonVO嵌套元素类型
     * @return 返回创建的JSON VO对象
     */
    public static <T> JsonVO<T> fail(T data) {
        return create(data, ResultStatus.FAIL);
    }

    /***
     * 静态构建处理失败数据对象
     * @param data 数据对象
     * @param status 状态码
     * @return
     * @param <T> 返回创建的JSON VO对象
     */
    public static <T> JsonVO<T> fail(T data, ResultStatus status) {
        return create(data, status);
    }
}
