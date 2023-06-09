package com.zeroone.star.project.j3.dto.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.ToString;

/**
 * <p>
 * 描述：查询组织地址分页信息
 * </p>
 * <p>版权：&copy;2023</p>
 * <p>地址：</p>
 *
 * @Author 18385
 * @version 1.0.0
 * @Date 2023/6/9 19:23
 */
@Data
@ToString
@ApiModel("分页查询指定组织地址列表")
public class OrgAddressDTO {
	@ApiModelProperty(value = "序号", example = "01", required = true)
	private String xh;

	@ApiModelProperty(value = "组织名称", example = "XXX公司", required = true)
	private String orgname;

	@ApiModelProperty(value = "组织地址", example = "中川大道xxx号", required = true)
	private String ormorgdzname;
}

