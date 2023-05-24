package com.zeroone.star.project.j3.dto.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.util.Date;

/**
 * <p>
 * 描述：组织信息数据传输对象
 * </p>
 * <p>版权：&copy;2023 </p>
 * <p>地址：</p>
 *
 * @version 1.0.0
 * @Author 18385
 * @Date 2023/5/19 0:40
 */
@Data
@ApiModel("组织信息传输对象")
public class OrgInfoDTO {
	@ApiModelProperty(value = "组织ID", example = "1", required = true)
	private String ormorinfosid;

	@ApiModelProperty(value = "组织名称", example = "XXX公司", required = true)
	private String ormorinfoname;

	@ApiModelProperty(value = "组织编码", example = "001", required = true)
	private String orgcode;

	@ApiModelProperty(value = "组织简称", example = "XXX", required = true)
	private String shortname;

	@ApiModelProperty(value = "上级组织ID", example = "1", required = true)
	private String porgid;

	@ApiModelProperty(value = "组织排序编号", example = "001", required = true)
	private String ordernum;

	@ApiModelProperty(value = "所属区域", example = "华东地区", required = true)
	private String belongregion;

	@ApiModelProperty(value = "补贴标准", example = "100元/月", required = true)
	private String substandard;

	@ApiModelProperty(value = "所属OU", example = "1", required = true)
	private String ouid;

	@DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
	@ApiModelProperty(value = "组织启用时间", example = "2021-01-01 00:00:00.000", required = true)
	private Date createdate;

	@ApiModelProperty(value = "组织性质", example = "法人单位", required = true)
	private String orgtype;

	@ApiModelProperty(value = "启停标识", example = "启用", required = true)
	private String startstopsign;

	@ApiModelProperty(value = "对应OU", example = "001", required = true)
	private String correspondingorg;

	// 以下是业务流程信息
	@ApiModelProperty(value = "更新人(不用再页面中写该列)", example = "李四", required = true)
	private String updateman;

	@DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
	@ApiModelProperty(value = "更新时间(不用在页面中写该列)", example = "2021-01-01 00:00:00.000", required = true)
	private Date updatedate;
}
