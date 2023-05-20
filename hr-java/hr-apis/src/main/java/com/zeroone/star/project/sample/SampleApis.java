package com.zeroone.star.project.sample;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sample.SampleDTO;
import com.zeroone.star.project.query.sample.SampleQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;

/**
 * <p>
 * 描述：测试API接口定义
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */


//参考示例
//@PreAuthorize("hasAnyAuthority('ROLE_SUPERADMIN','ehr-OrmDuty-Default-all')")
//@ApiOperation(value = "获取DEFAULT", tags = {"职务管理" } ,notes = "获取DEFAULT")
//@RequestMapping(method= RequestMethod.GET , value="/ormduties/fetchdefault")
//public ResponseEntity<List<OrmDutyDTO>> fetchDefault(OrmDutySearchContext context) {
//        Page<OrmDuty> domains = ormdutyService.searchDefault(context) ;
//        List<OrmDutyDTO> list = ormdutyMapping.toDto(domains.getContent());
//        return ResponseEntity.status(HttpStatus.OK)
//        .header("x-page", String.valueOf(context.getPageable().getPageNumber()))
//        .header("x-per-page", String.valueOf(context.getPageable().getPageSize()))
//        .header("x-total", String.valueOf(domains.getTotalElements()))
//        .body(list);
//        }
public interface SampleApis {
    /**
     * 测试分页查询
     * @param condition 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<SampleDTO>> queryAll(SampleQuery condition);

    /**
     * 通过编号查询数据
     * @param id 编号
     * @return 查询结果
     */
    JsonVO<SampleDTO> queryById(int id);
}
