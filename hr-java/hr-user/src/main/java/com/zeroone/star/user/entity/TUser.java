package com.zeroone.star.user.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 用户
 * </p>
 *
 * @author axiao
 * @since 2023-05-18
 */
@Getter
@Setter
@TableName("t_user")
public class TUser implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 用户标识
     */
    private String id;

    /**
     * 用户模式
     */
    private String username;

    /**
     * 建立人
     */
    private String password;

    /**
     * 邮箱
     */
    private String email;

    /**
     * 电话
     */
    private String phone;

    /**
     * 状态
     */
    private Integer state;

    /**
     * 登录名称
     */
    private String role;

    /**
     * 建立时间
     */
    private LocalDateTime createdate;


}
