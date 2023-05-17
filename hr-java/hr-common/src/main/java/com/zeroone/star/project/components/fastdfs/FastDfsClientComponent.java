package com.zeroone.star.project.components.fastdfs;

import io.github.bluemiaomiao.annotation.EnableFastdfsClient;
import io.github.bluemiaomiao.service.FastdfsClientService;
import org.apache.commons.io.FileUtils;
import org.springframework.stereotype.Component;

import javax.annotation.Resource;
import java.io.File;

/**
 * <p>
 * 描述：封装dfs上传、下载等常用方法
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
@Component
@EnableFastdfsClient
public class FastDfsClientComponent {

    @Resource
    private FastdfsClientService remoteService;

    /**
     * 文件上传
     *
     * @param fileName 文件全路径
     * @param extName  文件扩展名，不包含（.）
     * @return 上传结果信息
     * @throws Exception 存储失败异常
     */
    public FastDfsFileInfo uploadFile(String fileName, String extName) throws Exception {
        String[] info = remoteService.autoUpload(FileUtils.readFileToByteArray(new File(fileName)), extName);
        if (info != null) {
            return FastDfsFileInfo.builder()
                    .group(info[0])
                    .storageId(info[1])
                    .build();
        }
        return null;
    }

    /**
     * 文件上传
     *
     * @param fileName 文件全路径
     * @return 上传结果信息
     * @throws Exception 存储失败异常
     */
    public FastDfsFileInfo uploadFile(String fileName) throws Exception {
        return uploadFile(fileName, null);
    }

    /**
     * 上传文件
     *
     * @param fileContent 文件的内容，字节数组
     * @param extName     文件扩展名
     * @return 上传结果信息
     * @throws Exception 存储失败异常
     */
    public FastDfsFileInfo uploadFile(byte[] fileContent, String extName) throws Exception {
        String[] info = remoteService.autoUpload(fileContent, extName);
        if (info != null) {
            return FastDfsFileInfo.builder()
                    .group(info[0])
                    .storageId(info[1])
                    .build();
        }
        return null;
    }

    /**
     * 上传文件
     *
     * @param fileContent 件的内容，字节数组
     * @return 上传结果信息 [0]:服务器分组，[1]:服务器ID
     * @throws Exception 存储失败异常
     */
    public FastDfsFileInfo uploadFile(byte[] fileContent) throws Exception {
        return uploadFile(fileContent, null);
    }

    /**
     * 文件下载
     *
     * @param info 文件信息
     * @return 下载数据
     * @throws Exception 异常信息
     */
    public byte[] downloadFile(FastDfsFileInfo info) throws Exception {
        return remoteService.download(info.getGroup(), info.getStorageId());
    }

    /**
     * 删除文件
     *
     * @param info 文件信息
     * @return 删除结果 0表示删除成功
     * @throws Exception 异常信息
     */
    public int deleteFile(FastDfsFileInfo info) throws Exception {
        return remoteService.delete(info.getGroup(), info.getStorageId());
    }

    /**
     * 解析成url地址
     *
     * @param info      文件信息
     * @param urlPrefix 如：<a href="#">http://ip:port</a>
     * @param isToken   是否带防盗链
     * @return 获取失败返回null
     */
    public String fetchUrl(FastDfsFileInfo info, String urlPrefix, boolean isToken) {
        try {
            if (isToken) {
                return remoteService.autoDownloadWithToken(info.getGroup(), info.getStorageId(), urlPrefix);
            } else {
                return remoteService.autoDownloadWithoutToken(info.getGroup(), info.getStorageId(), urlPrefix);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }
}
