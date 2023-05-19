package com.zeroone.star.project.common;

import com.zeroone.star.project.query.common.ZzmmQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * @Description: 公共接口
 * @Author: Rqs
 * @Date: 2023/5/16 20:26
 */
public interface CommonApis {
    /**
     * @Description: 获取政治面貌下拉列表
     * @params: []
     * @return: JsonVO<ZzmmQuery>
     * @Author: Rqs
     * @Date: 2023/5/19 23:17
     */
    JsonVO<ZzmmQuery> queryZzmm();
}
