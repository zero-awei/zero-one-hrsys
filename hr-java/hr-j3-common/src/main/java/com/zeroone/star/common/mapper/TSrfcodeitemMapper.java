package com.zeroone.star.common.mapper;

import com.zeroone.star.common.entity.TSrfcodeitem;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.j3.dto.DropdownListOptionDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * 代码项 Mapper 接口
 * </p>
 *
 * @author H
 * @since 2023-05-28
 */
@Mapper
public interface TSrfcodeitemMapper extends BaseMapper<TSrfcodeitem> {
    /**
     * 分配状态下拉列表查询
     *
     * @return {@link List< DropdownListOptionDTO>}
     * @Author H_lzu
     * @Date 21:52 2023/5/28
     */
//    @Select("select `codeitemid` AS `key`, `codeitemname` AS `value` from t_srfcodeitem;")
    List<DropdownListOptionDTO> selectDistributionStatus(String codeitem);
}
