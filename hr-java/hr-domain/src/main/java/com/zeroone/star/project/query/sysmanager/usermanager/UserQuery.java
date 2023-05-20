package com.zeroone.star.project.query.sysmanager.usermanager;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;


/**
 * xiao
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("用户分页查询")
public class UserQuery extends PageQuery {

}
