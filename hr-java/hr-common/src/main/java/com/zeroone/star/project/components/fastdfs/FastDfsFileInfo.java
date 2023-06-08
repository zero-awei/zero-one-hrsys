package com.zeroone.star.project.components.fastdfs;

import lombok.Builder;
import lombok.Data;

/**
 * <p>
 * 描述：dfs文件结果信息
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
@Data
@Builder
public class FastDfsFileInfo {
    /**
     * 服务器分组
     */
    private String group;
    /**
     * 对应的存储资源ID
     */
    private String storageId;
}
