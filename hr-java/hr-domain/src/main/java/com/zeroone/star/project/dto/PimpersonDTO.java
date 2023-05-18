package com.zeroone.star.project.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * 描述：
 * 文件名：PimpersonDTO
 * 创建者：rqs
 * 创建时间：2023/5/15 23:50
 */
@ApiModel("政治面貌数据对象")
@Data
public class PimpersonDTO {
    /**
     * 政治面貌
     */
    @ApiModelProperty(value = "政治面貌", example = "30")
    private String zzmm;
}
