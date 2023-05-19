package com.zeroone.star.project.languageability;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.languageability.LanguageAbilityDTO;
import com.zeroone.star.project.query.languageability.LanguageAbilityQuery;
import com.zeroone.star.project.vo.JsonVO;

public interface LanguageAbility {

    /**
     * 分页查询语言能力
     * @param languageAbilities
     * @return
     */
    JsonVO<PageDTO<LanguageAbilityDTO>> queryAll(LanguageAbilityQuery languageAbilities);
}
