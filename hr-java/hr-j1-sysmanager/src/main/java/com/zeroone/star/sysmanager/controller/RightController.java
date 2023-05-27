package com.zeroone.star.sysmanager.controller;

import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.bean.copier.CopyOptions;
import cn.hutool.core.lang.func.Func1;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.core.metadata.TableFieldInfo;
import com.baomidou.mybatisplus.core.metadata.TableInfo;
import com.baomidou.mybatisplus.core.metadata.TableInfoHelper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sysmanager.rightmanagement.RightDTO;
import com.zeroone.star.project.query.sysmanager.comment.CommentQuery;
import com.zeroone.star.project.query.sysmanager.rightmanager.RightQuery;
import com.zeroone.star.project.sysmanager.RightApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.sysmanager.entity.Right;
import com.zeroone.star.sysmanager.service.RightService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.web.bind.annotation.*;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import java.util.List;
import java.util.Objects;

/**
 * The controller of {@link RightApis}, base on {@link RightService}
 *
 * @author authoralankay
 * @see RightApis
 * @see RightService
 */
@RestController
@RequestMapping("/right")
@Api(tags = "权限管理")
public class RightController implements RightApis {

    private RightService rightService;

    private static final String RIGHT_ROOT_ID = "0";

    public RightController(RightService rightService) {
        this.rightService = rightService;
    }

    /**
     * 分页查询列表
     *
     * @param query 查询条件
     * @return 查询结果
     */
    @ApiOperation(value = "分页查询列表")
    @GetMapping("/query-list")
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
        Page<Right> resultPage = rightService.page(page, queryWrapper);

        return JsonVO.success(PageDTO.create(resultPage, RightDTO.class));
    }

    @ApiOperation(value = "模糊查询列表")
    @GetMapping("/query-like")
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
        Page<Right> resultPage = rightService.page(page, queryWrapper);

        return JsonVO.success(PageDTO.create(resultPage, RightDTO.class));
    }

    @ApiOperation(value = "增加权限")
    @PostMapping("/add-right")
    @Override
    public JsonVO<Boolean> addRight(RightDTO dto) {
        // 字段 id 为 varchar(64) 类型，不能设置为自增，需要自己指定
        // 判断 id 是否重复
        String id = dto.getId();
        Right checkRight = rightService.getById(id);
        if (Objects.nonNull(checkRight)) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "id 重复");
        }
        // 判断 name 非空且不重复
        String name = dto.getName();
        boolean nameIsNullOrExist = Objects.isNull(name) ||
                Objects.nonNull(rightService.getOne(new QueryWrapper<Right>().lambda().eq(Right::getName, name)));
        if (nameIsNullOrExist) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "name 不能为空或已存在");
        }
        // 判断 linkUrl 非空且不重复
        String linkUrl = dto.getLinkUrl();
        boolean linkUrlIsNullOrExist = Objects.isNull(linkUrl) ||
                Objects.nonNull(rightService.getOne(new QueryWrapper<Right>().lambda().eq(Right::getLinkUrl, linkUrl)));
        if (linkUrlIsNullOrExist) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "link url 不能为空或已存在");
        }
        // 判断 parentRightId 是否存在
        String parentRightId = dto.getParentRightId();
        boolean parentRightIdNotExist = Objects.isNull(rightService.getById(parentRightId));
        if (parentRightIdNotExist) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "parent right id 不存在");
        }
        // 将 dto 的非空属性赋值给 right 权限，然后添加权限
        Right right = new Right();
        BeanUtil.copyProperties(dto, right, CopyOptions.create().setIgnoreNullValue(true));
        boolean result = rightService.save(right);

        if (result) {
            return JsonVO.success(true);
        }
        return JsonVO.fail(false);
    }

    @ApiOperation(value = "修改权限")
    @PostMapping("/modify-right")
    @Override
    public JsonVO<Boolean> modifyRight(RightDTO dto) {
        String id = dto.getId();
        Right right = rightService.getById(id);
        if (Objects.isNull(right)) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "权限不存在");
        }
        // 若修改了 name，则需判断 name 是否重复
        String name = dto.getName();
        boolean nameExist = !right.getName().equals(name) &&
                Objects.nonNull(rightService.getOne(new QueryWrapper<Right>().lambda().eq(Right::getName, name)));
        if (nameExist) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "修改后的 name 已存在");
        }
        // 若修改了 linkUrl，则需判断 linkUrl 是否重复
        String linkUrl = dto.getLinkUrl();
        boolean linkUrlExist = !right.getLinkUrl().equals(linkUrl) &&
                Objects.nonNull(rightService.getOne(new QueryWrapper<Right>().lambda().eq(Right::getLinkUrl, linkUrl)));
        if (linkUrlExist) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "修改后的 link url 已存在");
        }
        // 判断 parentRightId 是否存在
        String parentRightId = dto.getParentRightId();
        boolean parentRightIdNotExist = Objects.isNull(rightService.getById(parentRightId));
        if (parentRightIdNotExist) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "parent right id 不存在");
        }
        // 将 dto 的非空属性赋值给 right 权限，然后更新权限
        BeanUtil.copyProperties(dto, right, CopyOptions.create().setIgnoreNullValue(true));
        boolean result = rightService.updateById(right);

        if (result) {
            return JsonVO.success(true);
        }
        return JsonVO.fail(false);
    }

    @ApiOperation(value = "删除权限")
    @DeleteMapping("/remove-right")
    @Override
    public JsonVO<Boolean> removeRight(@RequestParam String id) {
        if (RIGHT_ROOT_ID.equals(id)) {
            // 不能删除根权限
            return JsonVO.create(false, ResultStatus.FORBIDDEN.getCode(), "不能删除根权限");
        }
        Right right = rightService.getById(id);
        if (Objects.isNull(right)) {
            return JsonVO.create(false, ResultStatus.PARAMS_INVALID.getCode(), "权限不存在");
        }
        boolean result = rightService.removeById(right);

        if (result) {
            return JsonVO.success(true);
        }
        return JsonVO.fail(false);
    }

    @ApiOperation(value = "修改状态")
    @PostMapping("/modify-status")
    @Override
    public JsonVO<Boolean> modifyStatus(@RequestParam String id) {
        Right right = rightService.getById(id);
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
        boolean result = rightService.updateById(right);

        if (result) {
            return JsonVO.success(true);
        }
        return JsonVO.fail(false);
    }
}
