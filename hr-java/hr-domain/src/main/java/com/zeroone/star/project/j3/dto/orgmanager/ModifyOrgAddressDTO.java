package com.zeroone.star.project.j3.dto.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.util.Date;

/**
 * <p>
 * 描述：更新指定组织地址信息
 * </p>
 * <p>版权：&copy;2023 </p>
 * <p>地址：</p>
 *
 * @Author 18385
 * @version 1.0.0
 * @Date 2023/5/22 16:08
 */
@Data
@ApiModel("更新指定组织地址信息（导入的地址也通过这个接口更新）")
public class ModifyOrgAddressDTO {
	@ApiModelProperty(value = "组织id", example = "1", required = true)
	private String ormorginfoid;

	@ApiModelProperty(value = "所属区域", example = "华东地区", required = true)
	private String belongregion;

	// 以下是业务流程信息
	@ApiModelProperty(value = "更新人", example = "李四", required = true)
	private String updateman;

	@DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
	@ApiModelProperty(value = "更新时间", example = "2021-01-01 00:00:00.000", required = true)
	private Date updatedate;
}

