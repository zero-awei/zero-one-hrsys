package com.zeroone.star.cpp.service;

import com.zeroone.star.cpp.config.FeignConfiguration;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.cpp.SampleDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.*;

import java.util.Map;

/**
 * <p>
 * 描述：示例声明式服务
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@FeignClient(
        name = "${cpp.sample.name}",
        url = "${cpp.sample.url}",
        fallbackFactory = SampleServiceFallBack.class,
        configuration = FeignConfiguration.class
)
public interface SampleService {
    @GetMapping("/sample")
    JsonVO<PageDTO<SampleDTO>> get(@RequestParam Map<String,Object> query);
    @PostMapping("/sample")
    JsonVO<Long> post(@RequestBody SampleDTO dto);
    @PutMapping("/sample")
    JsonVO<Long> put(@RequestBody SampleDTO dto);
    @DeleteMapping("/sample")
    JsonVO<Long> delete(@RequestBody SampleDTO dto);
}
