package com.zeroone.star.sample.controller;

import cn.hutool.core.date.DateTime;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.AllArgsConstructor;
import lombok.SneakyThrows;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.nio.charset.StandardCharsets;

/**
 * <p>
 * 描述：演示FastDFS文件操作
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Controller
@RequestMapping("file")
@Api(tags = "FastDfs文件操作")
public class FileController {
    @Resource
    private FastDfsClientComponent fastDfsClientComponent;

    @Value("${fastdfs.nginx-servers}")
    private String fileServerUrl;

    @SneakyThrows
    @ResponseBody
    @PostMapping("upload")
    @ApiOperation(value = "文件上传")
    public JsonVO<String> uploadFile(MultipartFile file) {
        // 获取文件的后缀名
        String fileName = file.getOriginalFilename();
        String suffix = fileName.substring(fileName.lastIndexOf(".") + 1);
        // 开始上传文件
        FastDfsFileInfo fastDfsFileInfo = fastDfsClientComponent.uploadFile(file.getBytes(), suffix);
        // 验证上传结果
        if (fastDfsFileInfo == null) {
            return JsonVO.fail(null);
        }
        // 返回下载地址
        return JsonVO.success(fastDfsClientComponent.fetchUrl(fastDfsFileInfo, "http://" + fileServerUrl, true));
    }

    @SneakyThrows
    @GetMapping(value = "download-image", produces = "image/jpeg")
    @ApiOperation(value = "图片下载")
    public ResponseEntity<byte[]> downloadImage(String group, String storageId) {
        // 下载文件
        FastDfsFileInfo info = FastDfsFileInfo.builder().group(group).storageId(storageId).build();
        byte[] bytes = fastDfsClientComponent.downloadFile(info);
        // 响应给前端
        HttpHeaders headers = new HttpHeaders();
        // 处理中文乱码
        String fileName = "img-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".jpg";
        fileName = new String(fileName.getBytes(StandardCharsets.UTF_8), StandardCharsets.ISO_8859_1);
        headers.setContentDispositionFormData("attachment", fileName);
        headers.setContentType(MediaType.IMAGE_JPEG);
        return new ResponseEntity<>(bytes, headers, HttpStatus.CREATED);
    }

    @SneakyThrows
    @DeleteMapping(value = "remove-file")
    @ApiOperation(value = "文件删除")
    @ResponseBody
    public JsonVO<Integer> removeFile(String group, String storageId) {
        FastDfsFileInfo info = FastDfsFileInfo.builder().group(group).storageId(storageId).build();
        int result = fastDfsClientComponent.deleteFile(info);
        if (result == 0) {
            return JsonVO.success(0);
        }
        return JsonVO.fail(result);
    }
}
