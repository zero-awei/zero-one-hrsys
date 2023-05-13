package com.zeroone.star.project.test;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.test.TestDTO;
import com.zeroone.star.project.query.test.TestQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 * 描述：TODO
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
public interface TestApis {
    /**
     *
     * @param query
     * @return
     */
    JsonVO<PageDTO<TestDTO>> queryAll(TestQuery query);
}
