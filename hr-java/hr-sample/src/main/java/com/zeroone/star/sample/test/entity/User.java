package com.zeroone.star.sample.test.entity;

import com.alibaba.excel.annotation.ExcelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：测试EasyExcel用户类
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Data
public class User {
    /**
     * value表示该属性对应的表头名称， index表示该属性所处的列的位置
     */
    @ExcelProperty(value = "编号", index = 0)
    private Integer id;
    @ExcelProperty(value = "姓名", index = 1)
    private String name;
    @ExcelProperty(value = "电话", index = 2)
    private String phone;
}
