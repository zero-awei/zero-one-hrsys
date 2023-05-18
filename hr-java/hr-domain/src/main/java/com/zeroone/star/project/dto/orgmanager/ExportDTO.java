package com.zeroone.star.project.dto.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：导出文件下载地址传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 浅墨
 * @version 1.0.0
 */
@ApiModel("导出文件下载地址传输对象")
@Data
public class ExportDTO {
    @ApiModelProperty(value = "导出文件下载地址", example = "http://xxx.xxx/xxx")
    private String url;
}
