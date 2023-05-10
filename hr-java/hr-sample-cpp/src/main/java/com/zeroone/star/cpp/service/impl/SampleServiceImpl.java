package com.zeroone.star.cpp.service.impl;

import com.zeroone.star.cpp.service.SampleService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.cpp.SampleDTO;
import com.zeroone.star.project.vo.JsonVO;
import lombok.AllArgsConstructor;

import java.util.Map;

/**
 * <p>
 * 描述：TODO
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@AllArgsConstructor
public class SampleServiceImpl implements SampleService {

    private Throwable throwable;

    private <T> JsonVO<T> setMessage(JsonVO<T> vo) {
        if (throwable.getMessage() != null) {
            vo.setMessage(throwable.getMessage());
        } else {
            vo.setMessage(throwable.getClass().toGenericString());
        }
        return vo;
    }

    @Override
    public JsonVO<PageDTO<SampleDTO>> get(Map<String, Object> query) {
        return setMessage(JsonVO.fail(null));
    }

    @Override
    public JsonVO<Long> post(SampleDTO dto) {
        return setMessage(JsonVO.fail(null));
    }

    @Override
    public JsonVO<Long> put(SampleDTO dto) {
        return setMessage(JsonVO.fail(null));
    }

    @Override
    public JsonVO<Long> delete(SampleDTO dto) {
        return setMessage(JsonVO.fail(null));
    }
}
