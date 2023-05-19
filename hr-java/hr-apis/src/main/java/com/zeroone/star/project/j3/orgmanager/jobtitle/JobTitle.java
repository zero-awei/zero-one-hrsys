package com.zeroone.star.project.j3.orgmanager.jobtitle;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j3.dto.jobtitle.JobTitleDTO;
import com.zeroone.star.project.j3.dto.languageability.LanguageAbilityDTO;
import com.zeroone.star.project.j3.query.jobtitle.JobTitleQuery;
import com.zeroone.star.project.j3.query.languageability.LanguageAbilityQuery;
import com.zeroone.star.project.vo.JsonVO;

public interface JobTitle {

    /**
     * 分页查询所有职务信息
     * @return
     */
    JsonVO<PageDTO<JobTitleDTO>> queryJobTitleList();

    /**
     * 修改指定职务信息
     * @param jobTitleDTO
     */
    void modifyJobTitle(JobTitleDTO jobTitleDTO);

}
