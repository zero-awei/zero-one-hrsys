package com.zeroone.star.orgmanager.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.orgmanager.entity.TOrmduty;
import com.zeroone.star.orgmanager.mapper.TOrmdutyMapper;
import com.zeroone.star.orgmanager.service.ITOrmdutyService;

import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import org.apache.poi.ss.usermodel.Sheet;
import org.apache.poi.ss.usermodel.Workbook;
import org.apache.poi.ss.usermodel.WorkbookFactory;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.io.ByteArrayInputStream;
import java.io.InputStream;
import java.nio.charset.StandardCharsets;

/**
 * <p>
 * 职务管理 服务实现类
 * </p>
 *
 * @author H
 * @since 2023-05-25
 */
@Service
public class TOrmdutyServiceImpl extends ServiceImpl<TOrmdutyMapper, TOrmduty> implements ITOrmdutyService {
    @Resource
    private FastDfsClientComponent fastDfsClientComponent;

    /**
     * 获取文件并插入数据库（导入职务）
     *
     * @param fastDfsFileInfo fastDfsFileInfo
     * @return {@link boolean}
     * @Author H_lzu
     * @Date 14:33 2023/6/3
     */
    @Override
    public void importExcelData(FastDfsFileInfo fastDfsFileInfo) throws Exception {
        // 解析Excel文件
        // 获取文件的字节数据
        byte[] fileBytes = fastDfsClientComponent.downloadFile(fastDfsFileInfo);

        InputStream inputStream = new ByteArrayInputStream(fileBytes);
        Workbook workbook = WorkbookFactory.create(inputStream);
        Sheet sheet = workbook.getSheetAt(0); // 假设导入的是第一个Sheet

//        // 遍历每一行数据，并将其插入数据库中
//        for (Row row : sheet) {
//            // 在这里执行插入数据库的逻辑，将row数据插入到数据库中
//            // 例如，假设数据库表名为 "t_ormduty"，插入的字段为 "codeitem"
//            // 请根据您的实际表名和字段名进行调整
//            Cell cell = row.getCell(0); // 假设要插入的数据在第一列
//            String rowData = cell.getStringCellValue(); // 假设单元格数据类型为字符串
//
//            // 创建实体对象，设置字段值并保存到数据库
//            TOrmduty entity = new TOrmduty();
//            entity.setCodeitem(rowData);
//            this.save(entity);
//        }
//        // 将字节数据转换为文件内容
//        String fileContent = new String(fileBytes, StandardCharsets.UTF_8);
//
//        // 按行读取文件内容
//        String[] lines = fileContent.split(System.lineSeparator());
//
//        // 遍历每一行数据，并将其插入数据库中
//        for (String line : lines) {
//            // 在这里执行插入数据库的逻辑，将line数据插入到数据库中
//            // 例如，假设数据库表名为 "your_table_name"，插入的字段为 "your_field_name"
//            // 请根据您的实际表名和字段名进行调整
//            TOrmduty entity = new TOrmduty();
//
//            service.save(entity);
        }

}
