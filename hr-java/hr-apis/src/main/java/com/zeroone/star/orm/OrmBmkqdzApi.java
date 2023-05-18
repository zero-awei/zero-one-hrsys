package com.zeroone.star.orm;


import com.zeroone.star.project.dto.orm.OrmBmkqdzDTO;
import com.zeroone.star.project.query.orm.OrmBmkqdzQuery;
import com.zeroone.star.project.vo.JsonVO;

public interface OrmBmkqdzApi {

    JsonVO<OrmBmkqdzDTO> modifyOrmBmkqdz(OrmBmkqdzQuery query);

}
