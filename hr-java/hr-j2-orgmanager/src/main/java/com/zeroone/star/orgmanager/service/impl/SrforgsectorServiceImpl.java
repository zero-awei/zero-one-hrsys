package com.zeroone.star.orgmanager.service.impl;

import com.zeroone.star.orgmanager.entity.Srforgsector;
import com.zeroone.star.orgmanager.mapper.SrforgsectorMapper;
import com.zeroone.star.orgmanager.service.ISrforgsectorService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.orgmanager.DeptDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 * 组织部门 服务实现类
 * </p>
 *
 * @author letian
 * @since 2023-05-21
 */
@Service
public class SrforgsectorServiceImpl extends ServiceImpl<SrforgsectorMapper, Srforgsector> implements ISrforgsectorService {
    @Resource
    private SrforgsectorMapper srforgsectorMapper;

    @Override
    public JsonVO<String> removeDeptByIds(DeptDTO deptDTO) {
        srforgsectorMapper.deleteDeptByIds(deptDTO);
        return JsonVO.success("删除成功！");
    }
}
