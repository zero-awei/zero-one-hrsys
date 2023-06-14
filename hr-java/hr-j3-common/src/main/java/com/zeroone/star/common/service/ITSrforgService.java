package com.zeroone.star.common.service;

import com.zeroone.star.common.entity.TSrforg;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * <p>
 * 组织机构 服务类
 * </p>
 *
 * @author tomcatcc
 * @since 2023-06-09
 */
public interface ITSrforgService extends IService<TSrforg> {

    	/**
    		 *查询组织名称
    		 * @param id
    		 * @return List
    		 */
        public List<String> queryOrganizationName(String id);
}
