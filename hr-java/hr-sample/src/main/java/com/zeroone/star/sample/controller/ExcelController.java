package com.zeroone.star.sample.controller;

import cn.hutool.core.date.DateTime;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.sample.test.entity.User;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import javax.annotation.PostConstruct;
import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 描述：演示Excel的使用
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Controller
@RequestMapping("excel")
@Api(tags = "Excel使用示例")
public class ExcelController {
    private List<User> users;

    @PostConstruct
    public void initData() {
        users = new ArrayList<>(50);
        for (int i = 1; i <= 50; i++) {
            User user = new User();
            user.setId(i);
            user.setName("姓名" + i);
            user.setPhone("phone" + i);
            users.add(user);
        }
    }

    @Resource
    EasyExcelComponent component;

    @SneakyThrows
    @GetMapping(value = "export", produces = "application/octet-stream")
    @ApiOperation(value = "导出数据")
    public ResponseEntity<byte[]> downloadImage() {
        // 创建输出流
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        // 导出数据到输出流
        component.export("测试", out, User.class, users);
        // 响应给前端
        HttpHeaders headers = new HttpHeaders();
        byte[] bytes = out.toByteArray();
        out.close();
        // 处理中文乱码
        String fileName = "test-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        fileName = new String(fileName.getBytes(StandardCharsets.UTF_8), StandardCharsets.ISO_8859_1);
        headers.setContentDispositionFormData("attachment", fileName);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        return new ResponseEntity<>(bytes, headers, HttpStatus.CREATED);
    }
}
