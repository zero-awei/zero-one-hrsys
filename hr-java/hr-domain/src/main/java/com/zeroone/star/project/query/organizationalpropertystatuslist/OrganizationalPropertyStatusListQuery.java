package com.zeroone.star.project.query.organizationalpropertystatuslist;

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
@ApiModel("组织性质状态查询")
public class OrganizationalPropertyStatusListQuery extends PageQuery {
    @ApiModelProperty(value = "姓名", example = "张三")
    private String name;
}
