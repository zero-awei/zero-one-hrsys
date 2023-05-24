package com.zeroone.star.common.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/**
 * @author mwx
 * @version 1.0
 * @description: TODO
 * @date 2023/5/24 10:12
 */
@Getter
@Setter
@TableName("zo_marital_status")
public class ZoMaritalStatus implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "id")
    private String id;

    private String maritalStatusType;

    private String maritalStatusCode;


}
