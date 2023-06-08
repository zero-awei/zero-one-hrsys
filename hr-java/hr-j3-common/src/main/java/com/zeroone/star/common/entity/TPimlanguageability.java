package com.zeroone.star.common.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 语言能力
 * </p>
 *
 * @author H
 * @since 2023-05-25
 */
@Getter
@Setter
@TableName("t_pimlanguageability")
public class TPimlanguageability implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 语言能力标识
     */
    private String pimlanguageabilityid;

    /**
     * 更新时间
     */
    private LocalDateTime updatedate;

    private Integer enable;

    /**
     * 外语等级获取时间
     */
    private LocalDateTime wydjhqsj;

    /**
     * 附件
     */
    private String fj;

    /**
     * 语种
     */
    private String wyyz;

    /**
     * 备注
     */
    private String bz;

    /**
     * 建立人
     */
    private String createman;

    /**
     * 更新人
     */
    private String updateman;

    /**
     * 外语等级
     */
    private String wydj;

    /**
     * 建立时间
     */
    private LocalDateTime createdate;

    /**
     * 语种
     */
    private String pimlanguageabilityname;

    /**
     * 人员信息标识
     */
    private String pimpersonid;

    /**
     * 记录所属
     */
    private String jlss;

    /**
     * 记录管理编号
     */
    private String jlglbh;

    /**
     * 记录审批状态
     */
    private String jlspzt;

    /**
     * 记录操作者
     */
    private String jlczz;

    /**
     * 拒绝原因
     */
    private String reason;


}
