package com.zeroone.star.ee.controller;

import cn.easyes.core.conditions.LambdaEsQueryWrapper;
import com.zeroone.star.ee.entity.Document;
import com.zeroone.star.ee.mapper.DocumentMapper;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 描述：测试使用Easy-ES控制器
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@RestController
@Api(tags = "测试EE")
public class TestUseEeController {

    @Resource
    private DocumentMapper documentMapper;

    /**
     * 测试添加数据
     * @param title   标题
     * @param content 描述
     * @return 返回影响数据条数
     */
    @GetMapping("/insert")
    @ApiOperation("添加数据")
    public Integer insert(String title, String content) {
        Document document = new Document();
        document.setTitle(title);
        document.setContent(content);
        return documentMapper.insert(document);
    }

    /**
     * 搜索数据
     * @param title 标题
     * @return 搜索结果
     */
    @GetMapping("/search")
    @ApiOperation("搜索数据")
    public List<Document> search(String title) {
        LambdaEsQueryWrapper<Document> wrapper = new LambdaEsQueryWrapper<>();
        wrapper.eq(Document::getTitle, title);
        return documentMapper.selectList(wrapper);
    }
}
