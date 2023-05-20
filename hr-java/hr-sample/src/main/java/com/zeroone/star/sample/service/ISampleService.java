package com.zeroone.star.sample.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sample.SampleDTO;
import com.zeroone.star.project.query.sample.SampleQuery;
import com.zeroone.star.sample.entity.Sample;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 * 服务类
 * </p>
 * @author awei
 * @since 2023-05-06
 */
public interface ISampleService extends IService<Sample> {
    /**
     * 分页查询示例表述
     * @param query 查询条件
     * @return 查询结果
     */
    PageDTO<SampleDTO> listAll(SampleQuery query);

    /**
     * 通过ID查询数据
     * @param id ID
     * @return 查询结果
     */
    SampleDTO getById(int id);

    /**
     * 测试调用seata服务
     * @return 执行结果
     */
    int testSeata();
}
