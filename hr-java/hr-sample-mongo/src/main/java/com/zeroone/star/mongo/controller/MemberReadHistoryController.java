package com.zeroone.star.mongo.controller;

import com.zeroone.star.mongo.entity.MemberReadHistory;
import com.zeroone.star.mongo.service.MemberReadHistoryService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 描述：会员商品浏览记录管理Controller
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@RestController
@Api(tags = "会员商品浏览记录管理")
public class MemberReadHistoryController {

    @Resource
    private MemberReadHistoryService memberReadHistoryService;

    /**
     * 创建浏览记录
     * @param memberReadHistory 数据对象
     * @return 返回影响数据条数
     */
    @PostMapping("/create")
    @ApiOperation("创建浏览记录")
    public Integer create(MemberReadHistory memberReadHistory) {
        return memberReadHistoryService.save(memberReadHistory);
    }

    /**
     * 删除数据
     * @param ids 删除ID集合，在knife4j中多个值用,分割
     * @return 搜索结果
     */
    @DeleteMapping("/delete")
    @ApiOperation("删除浏览记录")
    public Integer delete(@RequestParam("ids") List<String> ids) {
        return memberReadHistoryService.remove(ids);
    }

    /**
     * 搜索数据
     * @param memberId 会员编号
     * @return 搜索结果
     */
    @GetMapping("/list")
    @ApiOperation("展示浏览记录")
    public List<MemberReadHistory> search(Long memberId) {
        return memberReadHistoryService.list(memberId);
    }
}
