package com.zeroone.star.sysmanager.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;
import java.time.LocalDateTime;
import java.util.Date;

/**
 * <p>
 * 用户表
 * </p>
 *
 * @author axiao
 * @since 2023-05-25
 */
@Data
@TableName("zo_user")
@AllArgsConstructor
@NoArgsConstructor
public class User implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 用户id
     */
    private String id;

    /**
     * 用户名称
     */
    private String username;

    /**
     * 用户密码
     */
    private String password;

    /**
     * 邮箱
     */
    private String mail;

    /**
     * 联系电话
     */
    private String phone;

    /**
     * 注册时间
     */
    private LocalDateTime registTime;

    /**
     * 是否启用
     */
    private Integer isEnable;

    /**
     * creator
     */
    private String creator;


    /**
     * createtime
     */
    private LocalDateTime updateTime;

}
