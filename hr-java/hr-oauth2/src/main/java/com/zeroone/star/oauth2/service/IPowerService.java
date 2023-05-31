package com.zeroone.star.oauth2.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.oauth2.entity.Menu;
import com.zeroone.star.oauth2.entity.Power;
import org.apache.commons.math3.analysis.function.Pow;

import java.util.List;

/**
 * @author 风月
 * @date 2023/5/31 19:41
 */
public interface IPowerService extends IService<Power> {
    List<Power> listAllLinkUrl();
}
