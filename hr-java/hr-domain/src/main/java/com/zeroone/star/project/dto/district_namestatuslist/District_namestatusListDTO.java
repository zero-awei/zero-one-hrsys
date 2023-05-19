package com.zeroone.star.project.dto.district_namestatuslist;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author xiaoming xxx@163.com
 * @version 2023/5/19 22:01
 * @since JDK8
 */

@Data
@ApiModel("区(县)名称状态对象")
public class District_namestatusListDTO {
    @ApiModelProperty(value="唯一 id",example = "1")
    private  Integer id;

    @ApiModelProperty(value="姓名",example = "bob")
    private  String name;
}
