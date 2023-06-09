package com.zeroone.star.project.j3.orgmanager;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j3.dto.*;
import com.zeroone.star.project.dto.sample.SampleDTO;
import com.zeroone.star.project.j3.dto.orgmanager.JobTitleDTO;
import com.zeroone.star.project.j3.query.JobByNameQuery;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.multipart.MultipartFile;


/**
 * <p>
 * 描述：职务设置接口apis
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author H
 * @version 1.0.0
 * @date 2023/5/19 14:27
 */
public interface JobSetApis {
    /**
     * 导出所有职务
     * @return
     * @return {@link JsonVO< SampleDTO>}
     * @Author H_lzu
     * @Date 2023/5/19
     */
    JsonVO<ExportDTO> exportAllJobs() throws Exception;

    /**
     * 导入职务
     * @param file files
     * @return
     * @return {@link int}
     * @Author H_lzu
     * @Date 16:53 2023/5/19
     */
    JsonVO<String> importJobs(MultipartFile file);


    /**
     * 分页查询职务列表
     * @param pageQuery pageQuery
     * @return {@link JsonVO< PageDTO< JobTitleDTO>>}
     * @Author H_lzu
     * @Date 16:31 2023/6/8
     */

    JsonVO<PageDTO<JobTitleDTO>> queryJobTitleList(PageQuery pageQuery);

    /**
     * 修改所选若干个职务
     * @param ormdutyid   职务标识id
     * @param jobTitleDTO 修改职务信息传输对象
     * @return
     */
    JsonVO<Boolean> modifyJobTitle(String ormdutyid, JobTitleDTO jobTitleDTO);


    /**
     * 通过名称查询指定职务详情
     * 表 t_ormduty
     * @param condition 搜索框关键字＋页面分页信息
     * @return 搜索出的 PageDTO<JobDTO>
     */
    JsonVO<PageDTO<JobDTO>> queryJobByName(JobByNameQuery condition);


    /**
     * 删除职务信息
     * @param deletePositionDTO deletePositionDTO
     * @return {@link JsonVO< Boolean>}
     * @Author H_lzu
     * @Date 16:32 2023/6/8
     */
    JsonVO<Boolean> DeletePosition(DeletePositionDTO deletePositionDTO);


    /**
     * 增加职务组织信息
     * @param jobTitleDTO jobTitleDTO
     * @return {@link JsonVO< Boolean>}
     * @Author H_lzu
     * @Date 16:33 2023/6/8
     */
    JsonVO<Boolean> AddPosition(JobTitleDTO jobTitleDTO);

    /**
     * 导出组织（导出本页在前端完成）
     * @return {@link com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.j3.dto.ExportDTO>}
     * @Author H_lzu
     * @Date 16:27 2023/5/24
     */
    JsonVO<ExportDTO> exportAllOrgs();
}
