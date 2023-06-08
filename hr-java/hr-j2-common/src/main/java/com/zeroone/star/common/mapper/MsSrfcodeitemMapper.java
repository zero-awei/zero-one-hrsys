package com.zeroone.star.common.mapper;

import com.zeroone.star.common.entity.TSrfcodeitem;
import com.zeroone.star.project.dto.common.DropdownListOptionDTO;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.mapstruct.Mappings;

import java.util.List;

@Mapper(componentModel = "spring")
public interface MsSrfcodeitemMapper {
    @Mappings({
            @Mapping(target = "key", source = "codeitemvalue"),
            @Mapping(target = "value", source = "codeitemname")
    })
    DropdownListOptionDTO do2DTO(TSrfcodeitem tSrfcodeitem);

    List<DropdownListOptionDTO> dos2DTOs(List<TSrfcodeitem> dos);
}
