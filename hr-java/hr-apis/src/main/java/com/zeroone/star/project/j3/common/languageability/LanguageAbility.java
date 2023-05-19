package com.zeroone.star.project.j3.common.languageability;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j3.dto.languageability.LanguageAbilityDTO;
import com.zeroone.star.project.j3.query.languageability.LanguageAbilityQuery;
import com.zeroone.star.project.vo.JsonVO;

public interface LanguageAbility {

    /**
     * 分页查询某人的语言能力
     */
    JsonVO<PageDTO<LanguageAbilityDTO>> queryLanguageAbilityList(LanguageAbilityQuery query);
}
