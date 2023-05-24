package com.zeroone.star.project.j3.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：TODO
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author H
 * @version 1.0.0
 * @date 2023/5/19 16:41
 */
@ApiModel("导出所有职务/组织的文件url")
@Data
public class ExportDTO {
    @ApiModelProperty(value = "文件下载地址",example = "http://sssss")
    private String url;
}
