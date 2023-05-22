package com.zeroone.star.project.query.orgmanager;

/**
  * @author：letian
  * @date  2023/5/21
  * @description：部门查询对象:多id
  * @version: 1.0
*/

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

@Data
@ApiModel("部门数据传输对象")
public class DeptQuery2 {
    @ApiModelProperty(value = "多个部门标识ids", example = "7874AED2-5E83-4A0E-828A-0B88ED020599,....")
    private List<String> orgSectorIds;
}
