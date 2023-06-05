package com.zeroone.star.project.vo.sysmanager;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.*;
import java.util.Date;

@Data
@ApiModel("用户传输数据对象")
public class UserVO {

    @ApiModelProperty(value = "id", example = "自动生成")
    private String id;

    @NotBlank(message = "Username must not be blank")
    @ApiModelProperty(value = "用户名", example = "张三")
    private String username;

    @ApiModelProperty(value = "注册时间", example = "自动生成")
    private Date registTime;

    @Email(message = "The mailbox format is incorrect")
    @ApiModelProperty(value = "电子邮件", example = "2132123113@qq.com")
    private String mail;

    @ApiModelProperty(value = "电话", example = "1234656")
    private String phone;


    @Max(value = 1,message = "The maximum is 1")
    @Min(value = 0,message = "The minimum value is 0")
    @ApiModelProperty(value = "是/否激活", example = "1")
    private Integer isEnable;

    @ApiModelProperty(value = "创建人", example = "自动生成")
    private String creator;

    @ApiModelProperty(value = "修改时间", example = "自动生成")
    private Date updateTime;
}
