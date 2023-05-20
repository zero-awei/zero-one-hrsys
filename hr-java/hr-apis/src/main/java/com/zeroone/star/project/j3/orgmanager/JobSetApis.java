package com.zeroone.star.project.j3.orgmanager;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.sample.SampleDTO;
import com.zeroone.star.project.j3.dto.AllJobsDTO;
import com.zeroone.star.project.j3.dto.ExportDTO;
import com.zeroone.star.project.j3.dto.orgmanager.JobTitleDTO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

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
     *
     * @return
     * @return {@link JsonVO< SampleDTO>}
     * @Author H_lzu
     * @Date 2023/5/19
     */
    JsonVO<ExportDTO> exportAllJobs();

    /**
     * 导入职务
     *
     * @param jobs jobs
     * @return
     * @return {@link int}
     * @Author H_lzu
     * @Date 16:53 2023/5/19
     */
    JsonVO<Integer> importJobs(List<AllJobsDTO> jobs);

    /**
     * 查询职务列表
     * @return
     */
    public JsonVO<PageDTO<JobTitleDTO>> queryJobTitleList();

    /**
     * 修改所选若干个职务
     * @param ids
     */
    public void modifyJobTitle(List<JobTitleDTO> ids);


}
