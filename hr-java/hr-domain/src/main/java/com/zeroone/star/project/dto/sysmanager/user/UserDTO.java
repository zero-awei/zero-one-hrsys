package com.zeroone.star.project.dto.sysmanager.user;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.util.Date;

@Data
@ApiModel("用户传输数据对象")
public class UserDTO {

    @ApiModelProperty(value = "id", example = "abc1")
    private String id;

    @ApiModelProperty(value = "用户名", example = "张三")
    private String username;

    @ApiModelProperty(value = "密码", example = "password")
    private String password;

    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @ApiModelProperty(value = "注册时间", example = "2023-11-12")
    private Date joinDate;

    @ApiModelProperty(value = "电子邮件", example = "2132123113@qq.com")
    private String email;

    @ApiModelProperty(value = "电话", example = "1234656")
    private String phone;


    @ApiModelProperty(value = "已激活", example = "1")
    private Integer state;

    @ApiModelProperty(value = "角色", example = "管理员")
    private String userAndRole;


}
