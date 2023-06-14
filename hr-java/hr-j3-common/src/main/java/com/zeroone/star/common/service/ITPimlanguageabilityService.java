package com.zeroone.star.common.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.common.entity.TPimlanguageability;

import java.util.List;

/**
 * <p>
 * 语言能力 服务类
 * </p>
 *
 * @author loop
 * @since 2023-05-29
 */
public interface ITPimlanguageabilityService extends IService<TPimlanguageability> {

    /**
     * 查询外语等级
     * @param id
     * @return
     */
    public List<String> queryLanguageLevel(String id);

    /**
     * 查询语种类型
     * @param id
     * @return
     */
    public List<String> queryLanguageType(String id);

    /**
     * 查询与本人关系
     * @param id
     * @return
     */
    public List<String> queryRelationship(String id);

}
