package com.zeroone.star.orgmanager.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.orgmanager.entity.Orgsector;
import com.zeroone.star.project.dto.orgmanager.OrgsectorDTO;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

/**
 * <p>
 * 组织信息 Mapper 接口
 * </p>
 *
 * @author rqs
 * @since 2023-05-19
 */
@Mapper
public interface OrmMapper extends BaseMapper<Orgsector> {

}
