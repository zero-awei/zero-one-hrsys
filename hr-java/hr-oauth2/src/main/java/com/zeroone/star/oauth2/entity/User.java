package com.zeroone.star.oauth2.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.sql.Time;
import java.time.LocalDateTime;

/**
 * <p>
 * zo_user 用户表
 * </p>
 *
 * @author 风月
 */
@Getter
@Setter
@TableName("zo_user")
public class User implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 用户编号
     */
    @TableId(value = "id", type = IdType.AUTO)
    private Integer id;

    /**
     * 账户名
     */
    private String username;

    /**
     * 密码
     */
    private String password;

    /**
     * 是否启用
     */
    private int isEnable;

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
    private Time registerTime;

}

