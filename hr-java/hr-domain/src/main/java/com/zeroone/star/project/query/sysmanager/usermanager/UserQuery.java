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
 * @author axiao
 * @version 1.0.0
 */

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("用户分页查询")
public class UserQuery extends PageQuery {

    @ApiModelProperty(value = "id", example = "abc1")
    private String id;

    @ApiModelProperty(value = "用户名", example = "张三")
    private String username;


    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "注册时间", example = "2023-11-12 12:12:12")
    private Date registTime;

    @ApiModelProperty(value = "电子邮件", example = "2132123113@qq.com")
    private String mail;

    @ApiModelProperty(value = "电话", example = "1234656")
    private String phone;


    @ApiModelProperty(value = "已激活", example = "1")
    private Integer isEnable;

}
