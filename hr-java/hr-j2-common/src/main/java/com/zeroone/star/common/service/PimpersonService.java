package com.zeroone.star.common.service;

import com.zeroone.star.common.entity.Pimperson;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;

/**
 * <p>
 * 人员信息 服务类
 * </p>
 *
 * @author rqs
 * @since 2023-05-17
 */
public interface PimpersonService extends IService<Pimperson> {
    @PostMapping("/save-pimperson")
    JsonVO<String> savePimperson(@RequestParam String zzmm);
}
