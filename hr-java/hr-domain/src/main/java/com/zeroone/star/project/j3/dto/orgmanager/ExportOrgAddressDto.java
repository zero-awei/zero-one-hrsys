package com.zeroone.star.project.j3.dto.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：导出组织地址传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 梧桐
 * @version 1.0.0
 */
@ApiModel("导出指定组织地址的文件url")
@Data
public class ExportOrgAddressDto {
    @ApiModelProperty(value = "文件下载地址", example = "http://xxxx")
    private String url;

}
