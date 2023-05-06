package com.zeroone.star.project.cpp;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.cpp.SampleDTO;
import com.zeroone.star.project.query.cpp.SampleQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 * 描述：获取cpp模块接口定义
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
public interface SampleApis {
    /**
     * 获取cpp中的数据接口
     * @param query 查询对象
     * @return 查询结果
     */
    JsonVO<PageDTO<SampleDTO>> queryAll(SampleQuery query);

    /**
     * 添加数据到数据库
     * @param dto 数据对象
     * @return 新增数据唯一编号
     */
    JsonVO<Long> addData(SampleDTO dto);

    /**
     * 修改数据
     * @param dto 修改数据内容
     * @return 修改后的数据
     */
    JsonVO<Long> modifyData(SampleDTO dto);

    /**
     * 删除数据
     * @param dto 删除数据对象
     * @return 删除数据的编号
     */
    JsonVO<Long> removeData(SampleDTO dto);
}
