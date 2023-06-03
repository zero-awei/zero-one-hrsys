package com.zeroone.star.sysmanager.service.impl;

import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.bean.copier.CopyOptions;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.metadata.TableFieldInfo;
import com.baomidou.mybatisplus.core.metadata.TableInfo;
import com.baomidou.mybatisplus.core.metadata.TableInfoHelper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.rightmanagement.RightDTO;
import com.zeroone.star.project.query.sysmanager.comment.CommentQuery;
import com.zeroone.star.project.query.sysmanager.rightmanager.RightQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.sysmanager.entity.Right;
import com.zeroone.star.sysmanager.mapper.RightMapper;
import com.zeroone.star.sysmanager.service.RightService;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.Objects;

/**
 * The implementation of {@link RightService}, base on {@link ServiceImpl}
 *
 * @author authoralankay
 * @see RightService
 * @see ServiceImpl
 */
@Service
public class RightServiceImpl extends ServiceImpl<RightMapper, Right> implements RightService {

    private static final String RIGHT_ROOT_ID = "0";

    @Override
    public JsonVO<PageDTO<RightDTO>> queryAll(RightQuery query) {
        // 创建分页对象
        long pageIndex = query.getPageIndex();
        long pageSize = query.getPageSize();
        Page<Right> page = new Page<>(pageIndex, pageSize);
        // 构建查询条件
        LambdaQueryWrapper<Right> queryWrapper = new LambdaQueryWrapper<>();
        String name = query.getName();
        if (Objects.nonNull(name)) {
            queryWrapper.eq(Right::getName, name);
        }
        String linkUrl = query.getLinkUrl();
        if (Objects.nonNull(linkUrl)) {
            queryWrapper.eq(Right::getLinkUrl, linkUrl);
        }
        Integer priority = query.getPriority();
        if (Objects.nonNull(priority)) {
            queryWrapper.eq(Right::getPriority, priority);
        }
        Integer isEnable = query.getIsEnable();
        if (Objects.nonNull(isEnable)) {
            queryWrapper.eq(Right::getIsEnable, isEnable);
        }
        Integer level = query.getLevel();
        if (Objects.nonNull(level)) {
            queryWrapper.eq(Right::getLevel, level);
        }
        // 执行分页查询
        Page<Right> resultPage = page(page, queryWrapper);

        return JsonVO.success(PageDTO.create(resultPage, RightDTO.class));
    }

    @Override
    public JsonVO<PageDTO<RightDTO>> queryLike(CommentQuery query) {
        // 创建分页对象
        long pageIndex = query.getPageIndex();
        long pageSize = query.getPageSize();
        Page<Right> page = new Page<>(pageIndex, pageSize);
        // 构建查询条件
        String queryLike = query.getQuery();
        QueryWrapper<Right> queryWrapper = new QueryWrapper<>();
        TableInfo tableInfo = TableInfoHelper.getTableInfo(Right.class);
        List<TableFieldInfo> fieldList = tableInfo.getFieldList();
        for (TableFieldInfo field : fieldList) {
            queryWrapper.or(wrapper -> wrapper.like(field.getColumn(), queryLike));
        }
        // 执行分页查询
        Page<Right> resultPage = page(page, queryWrapper);

        return JsonVO.success(PageDTO.create(resultPage, RightDTO.class));
    }

    @Override
    public JsonVO<Boolean> addRight(RightDTO dto) {
        // 判断 id 是否重复
        String id = dto.getId();
        Right checkRight = getById(id);
        if (Objects.nonNull(checkRight)) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "id 重复");
        }
        // 判断 parentRightId 是否存在
        String parentRightId = dto.getParentRightId();
        boolean parentRightIdNotExist = Objects.isNull(getById(parentRightId));
        if (parentRightIdNotExist) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "parent right id 不存在");
        }
        // 将 dto 的非空属性赋值给 right 权限，然后添加权限
        Right right = new Right();
        BeanUtil.copyProperties(dto, right, CopyOptions.create().setIgnoreNullValue(true));
        boolean result = save(right);

        if (result) {
            return JsonVO.success(true);
        }
        return JsonVO.fail(false);
    }

    @Override
    public JsonVO<Boolean> modifyRight(RightDTO dto) {
        String id = dto.getId();
        Right right = getById(id);
        if (Objects.isNull(right)) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "权限不存在");
        }
        // 判断 parentRightId 是否存在
        String parentRightId = dto.getParentRightId();
        boolean parentRightIdNotExist = Objects.isNull(getById(parentRightId));
        if (parentRightIdNotExist) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "parent right id 不存在");
        }
        // 将 dto 的非空属性赋值给 right 权限，然后更新权限
        BeanUtil.copyProperties(dto, right, CopyOptions.create().setIgnoreNullValue(true));
        boolean result = updateById(right);

        if (result) {
            return JsonVO.success(true);
        }
        return JsonVO.fail(false);
    }

    @Override
    public JsonVO<Boolean> removeRight(String id) {
        if (RIGHT_ROOT_ID.equals(id)) {
            // 不能删除根权限
            return JsonVO.create(false, ResultStatus.FORBIDDEN.getCode(), "不能删除根权限");
        }
        Right right = getById(id);
        if (Objects.isNull(right)) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "权限不存在");
        }
        boolean result = removeById(right);

        if (result) {
            return JsonVO.success(true);
        }
        return JsonVO.fail(false);
    }

    @Override
    public JsonVO<Boolean> modifyStatus(String id) {
        Right right = getById(id);
        if (Objects.isNull(right)) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "权限不存在");
        }
        Integer isEnable = right.getIsEnable();
        if (Objects.isNull(isEnable)) {
            // 若 isEnable 为空说明数据库有脏数据
            return JsonVO.create(false, ResultStatus.SERVER_ERROR.getCode(), "数据库字段数据异常");
        }
        if (isEnable.equals(1)) {
            right.setIsEnable(0);
        } else {
            right.setIsEnable(1);
        }
        boolean result = updateById(right);

        if (result) {
            return JsonVO.success(true);
        }
        return JsonVO.fail(false);
    }
}
