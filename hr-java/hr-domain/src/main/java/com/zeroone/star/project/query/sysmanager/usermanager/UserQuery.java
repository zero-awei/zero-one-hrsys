package com.zeroone.star.project.query.sysmanager.usermanager;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;
import org.springframework.format.annotation.DateTimeFormat;

import java.util.Date;

/**
 * <p>
 * 描述：用户查询数据对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author
 * @version 1.0.0
 */

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("用户分页查询")
public class UserQuery extends PageQuery {

    @ApiModelProperty(value = "用户名", example = "张三")
    private String username;

    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @ApiModelProperty(value = "注册时间", example = "2023-11-12")
    private Date joinDate;

    @ApiModelProperty(value = "电子邮件", example = "2132123113@qq.com")
    private String email;

    @ApiModelProperty(value = "电话", example = "1234656")
    private String phone;

    @ApiModelProperty(value = "是否激活", example = "1")
    private Integer state;

    @ApiModelProperty(value = "角色", example = "管理员")
    private String userAndRole;

}