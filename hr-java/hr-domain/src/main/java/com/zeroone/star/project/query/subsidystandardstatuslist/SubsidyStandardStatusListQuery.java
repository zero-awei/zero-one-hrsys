package com.zeroone.star.project.query.subsidystandardstatuslist;

/**
 * @author abner
 * @version 1.0
 */
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("补贴标准状态查询")
public class SubsidyStandardStatusListQuery extends PageQuery {
    @ApiModelProperty(value = "姓名", example = "张三")
    private String name;
}
