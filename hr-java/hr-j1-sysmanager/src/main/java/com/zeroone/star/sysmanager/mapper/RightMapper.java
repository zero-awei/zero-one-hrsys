package com.zeroone.star.sysmanager.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.sysmanager.entity.Menu;
import com.zeroone.star.sysmanager.entity.Right;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * The mapper of {@link Right}, base on {@link BaseMapper}
 *
 * @author authoralankay
 * @see Right
 * @see BaseMapper
 */
@Mapper
public interface RightMapper extends BaseMapper<Right> {
    List<Right> selectByRoleName(String roleName);
}
