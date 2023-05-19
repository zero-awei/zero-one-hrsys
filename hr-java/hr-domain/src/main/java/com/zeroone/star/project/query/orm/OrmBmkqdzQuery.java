package com.zeroone.star.project.query.orm;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author mwx
 * @version 1.0
 * @description: TODO
 * @date 2023/5/18 15:20
 */

@ApiModel("指定部门查询")
@Data
public class OrmBmkqdzQuery {

    @ApiModelProperty(value = "部门唯一标识",example = "1")
    private String ormorgdzid;

    @ApiModelProperty(value = "部门考勤地址唯一标识",example = "1")
    private String ormbmkqdzid;

    @ApiModelProperty(value = "部门考勤地址名",example = "XX省XX市XX区XX路XX号")
    private String ormbmkqdzname;

}
