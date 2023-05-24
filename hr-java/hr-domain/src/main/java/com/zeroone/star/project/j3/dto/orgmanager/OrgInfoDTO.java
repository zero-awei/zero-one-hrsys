package com.zeroone.star.project.j3.dto.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

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
	@ApiModelProperty(value = "组织名称", example = "XXX公司")
	private String orgInfoName;
	@ApiModelProperty(value = "组织编码", example = "001")
	private String orgCode;
	@ApiModelProperty(value = "组织简称", example = "XXX")
	private String shortName;
	@ApiModelProperty(value = "上级组织", example = "1")
	private String pOrgId;
	@ApiModelProperty(value = "组织排序编号", example = "001")
	private String orderNum;
	@ApiModelProperty(value = "所属区域", example = "华东地区")
	private String belongRegion;
	@ApiModelProperty(value = "补贴标准", example = "100元/月")
	private String subStandard;
	@ApiModelProperty(value = "所属OU", example = "1", required = false)
	private String ouId;
	@ApiModelProperty(value = "组织启用时间", example = "2021-01-01 00:00:00")
	private Date createDate;
	@ApiModelProperty(value = "组织性质", example = "法人单位", required = false)
	private String orgType;
	@ApiModelProperty(value = "启停标识", example = "启用")
	private String startStopSign;
	@ApiModelProperty(value = "对应OU", example = "001", required = false)
	private String correspondingOu;

	// 以下是业务流程信息
	@ApiModelProperty(value = "创建人", example = "张三", hidden = true)
	private String createMan;
	@ApiModelProperty(value = "更新人", example = "李四", hidden = true)
	private String updateMan;
	@ApiModelProperty(value = "更新时间", example = "2021-01-01 00:00:00", hidden = true)
	private Date updateDate;
}
