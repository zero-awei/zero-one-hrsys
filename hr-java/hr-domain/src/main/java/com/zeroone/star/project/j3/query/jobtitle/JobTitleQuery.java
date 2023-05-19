package com.zeroone.star.project.j3.query.jobtitle;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("职务信息查询对象")
public class JobTitleQuery extends PageQuery {

    @NotBlank(message = "职务名称不能为空")
    @ApiModelProperty(value = "职务名称", example = "董事长")
    private String title;

}
