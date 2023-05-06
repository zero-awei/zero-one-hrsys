package com.zeroone.star.project.components.poi;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.ToString;
import org.apache.poi.ss.usermodel.Workbook;

/**
 * <p>
 * 描述：自定义WorkBook
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
@AllArgsConstructor
@Getter
@ToString
public class MyWorkBook {
    /**
     * 是否是新建的空工作薄
     */
    private boolean isNull;

    /**
     * 关联一个工作薄对象
     */
    private Workbook workbook;
}
