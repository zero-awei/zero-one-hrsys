package com.zeroone.star.project.common;

import com.zeroone.star.project.dto.post.GwflDTO;
import com.zeroone.star.project.dto.post.PostNatureDTO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
  * @author：letian
  * @date  2023/5/19
  * @description：共用接口：岗位分类和岗位性质列表
  * @version: 1.0
*/
public interface commonApis {
    /**
     * @param :
     * @return JsonVO<List<GwflDTO>> 部门分类信息
     * @author 乐天
     * @description 获取部门分类下拉列表
     * @date 2023/5/20 0:02
     */
    JsonVO<List<GwflDTO>> queryGwfl();

    /**
     * @param :
     * @return JsonVO<List<PostNatureDTO>> 部门性质信息
     * @author 乐天
     * @description 获取部门性质下拉列表
     * @date 2023/5/20 0:03
     */
    JsonVO<List<PostNatureDTO>> queryPostNature();
}
