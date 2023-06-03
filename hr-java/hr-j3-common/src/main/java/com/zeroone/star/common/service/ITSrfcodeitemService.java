package com.zeroone.star.common.service;

import com.zeroone.star.common.entity.TSrfcodeitem;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.j3.query.common.DisciplineTypeQuery;
import com.zeroone.star.project.j3.query.common.EducationTypeQuery;

import java.util.List;

/**
 * <p>
 * 代码项 服务类
 * </p>
 *
 * @author wutong
 * @since 2023-05-30
 */
public interface ITSrfcodeitemService extends IService<TSrfcodeitem> {
    public List<String> listEducationType(EducationTypeQuery education);

    public List<String> listDisciplineType(DisciplineTypeQuery discipline);
}
