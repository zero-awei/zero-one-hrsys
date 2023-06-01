package com.zeroone.star.common.service;

import com.zeroone.star.project.dto.common.ZzmmDTO;
import org.springframework.web.bind.annotation.GetMapping;

import java.util.List;

/**
 * 描述：
 * 文件名：zzmmService
 * 创建者：rqs
 * 创建时间：2023/5/19 23:11
 */
public interface ZzmmService {
    @GetMapping("/get-zzmm")
    public List<ZzmmDTO> getZzmm();
}
