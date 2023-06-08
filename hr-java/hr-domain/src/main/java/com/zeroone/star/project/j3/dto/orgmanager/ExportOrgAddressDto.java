package com.zeroone.star.project.j3.dto.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@ApiModel("导出指定组织地址的文件url")
@Data
public class ExportOrgAddressDto {
    @ApiModelProperty(value = "文件下载地址", example = "http://xxxx")
    private String url;

}