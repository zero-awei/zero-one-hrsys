package com.zeroone.star.project.dto.dashboard;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author mwx
 * @version 1.0
 * @description: TODO
 * @date 2023/5/18 11:44
 */
@Data
@ApiModel("职业资格对象")
public class PimVocationalDTO {

    @ApiModelProperty(value = "职业资格名",example = "软件设计师")
    private String qualificationName;

    @ApiModelProperty(value = "职业资格数量",example = "1")
    private Integer countNum;

}
