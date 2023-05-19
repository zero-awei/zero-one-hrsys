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
     * @param gwflDTO: 部门分类数据对象
     * @return JsonVO<List<GwflDTO>> 部门分类信息
     * @author 乐天
     * @description
     * @date 2023/5/19 23:58
     */
    JsonVO<List<GwflDTO>> queryGwfl(GwflDTO gwflDTO);

    JsonVO<List<PostNatureDTO>> queryPostNature(PostNatureDTO postNatureDTO);
}
