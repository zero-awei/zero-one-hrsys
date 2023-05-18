package com.zeroone.star.project.rqscommon;

import com.zeroone.star.project.dto.PimpersonDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * @Description: 公共接口
 * @Author: Rqs
 * @Date: 2023/5/16 20:26
 */
public interface CommonApis {
    /**
     * @Description: 通过政治面貌下拉列表设置政治面貌信息
     * @params: [politicalAffiliationDTO]
     * @return: Long
     * @Author: Rqs
     * @Date: 2023/5/16 20:42
     */
    JsonVO<String> addPimperson(PimpersonDTO pimpersonDTO);
}
