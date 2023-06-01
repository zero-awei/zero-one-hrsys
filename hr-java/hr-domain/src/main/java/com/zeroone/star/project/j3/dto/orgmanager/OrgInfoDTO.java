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
	@ApiModelProperty(value = "组织id", example = "1", required = true)
	private String orgid;

	@ApiModelProperty(value = "组织名称", example = "XXX公司", required = true)
	private String orgname;

	@ApiModelProperty(value = "组织编号", example = "001", required = true)
	private String orgcode;

	@ApiModelProperty(value = "组织简称", example = "XXX", required = true)
	private String shortname;

	@ApiModelProperty(value = "上级组织id", example = "1", required = true)
	private String porgid;

	@ApiModelProperty(value = "上级组织", example = "XXX公司", required = true)
	private String porgname;

	@ApiModelProperty(value = "排序号", example = "001", required = true)
	private String px;

	@ApiModelProperty(value = "所属区域", example = "华东地区", required = true)
	private String gsss;

	@ApiModelProperty(value = "补贴标准", example = "100元/月", required = true)
	private String btqy;

	@ApiModelProperty(value = "所属ou", example = "1", required = true)
	private String ssou;

	@DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
	@ApiModelProperty(value = "组织启用时间", example = "2021-01-01 00:00:00.000", required = true)
	private Date zzcjsj;

	@ApiModelProperty(value = "组织性质", example = "法人单位", required = true)
	private String legalentity;

	@ApiModelProperty(value = "启停标识", example = "启用", required = true)
	private String startstopsign;

	@ApiModelProperty(value = "对应ou", example = "001", required = true)
	private String correspondingorg;

	// 以下是业务流程信息
	@ApiModelProperty(value = "更新人(不用再页面中写该列)", example = "李四", required = true)
	private String updateman;

	@DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
	@ApiModelProperty(value = "更新时间(不用在页面中写该列)", example = "2021-01-01 00:00:00.000", required = false)
	private Date updatedate;
}