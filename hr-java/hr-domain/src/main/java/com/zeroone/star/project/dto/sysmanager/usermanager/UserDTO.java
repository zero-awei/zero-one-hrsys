package com.zeroone.star.project.dto.sysmanager.usermanager;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import javax.validation.constraints.*;
import java.util.Date;

@Data
@ApiModel("用户传输数据对象")
public class UserDTO {

    @NotBlank(message = "id must not be blank")
    @ApiModelProperty(value = "id", example = "abc1")
    private String id;

    @NotBlank(message = "Username must not be blank")
    @ApiModelProperty(value = "用户名", example = "张三")
    private String username;

    @NotBlank(message = "Password must not be blank")
    @Size(min = 6, message = "Password must have at least 8 characters")
    @ApiModelProperty(value = "密码", example = "password")
    private String password;

    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @ApiModelProperty(value = "注册时间", example = "2023-11-12")
    private Date registTime;

    @ApiModelProperty(value = "电子邮件", example = "2132123113@qq.com")
    private String mail;

    @ApiModelProperty(value = "电话", example = "1234656")
    private String phone;


    @Max(value = 1,message = "The maximum is 1")
    @Min(value = 0,message = "The minimum value is 0")
    @ApiModelProperty(value = "是/否激活", example = "1")
    private Integer isEnable;
}
