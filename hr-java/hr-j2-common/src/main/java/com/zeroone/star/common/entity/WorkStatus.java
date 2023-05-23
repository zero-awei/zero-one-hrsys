package com.zeroone.star.common.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/**
 * @author mwx
 * @version 1.0
 * @description: TODO
 * @date 2023/5/23 23:37
 */
@Getter
@Setter
@TableName("zo_work_status")
public class WorkStatus implements Serializable {

    private static final long serialVersionUID = 1L;

    private String id;

    private String workStatusType;

    private String workStatusCode;



}
