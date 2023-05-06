package com.zeroone.star.project.components.poi;

import cn.hutool.core.date.DateTime;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.apache.poi.ss.usermodel.*;
import org.apache.poi.xssf.streaming.SXSSFWorkbook;
import org.springframework.stereotype.Component;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.lang.reflect.Field;
import java.util.Date;
import java.util.List;

/**
 * <p>
 * 描述：POI Excel操作组件
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
@Component
public class ExcelComponent {

    /**
     * 创建工作薄
     * @param filePath 文件保存路径
     * @return 返回工作薄对象
     */
    public MyWorkBook createWorkBook(String filePath) {
        try {
            //通过excel文件创建一个工作簿
            Workbook workbook = WorkbookFactory.create(new File(filePath));
            return new MyWorkBook(false, workbook);
        } catch (IOException e) {
            //excel文件不存在则创建一个空的工作薄
            Workbook workbook = createNullWorkBook(filePath.endsWith(".xlsx") ? 2 : 1);
            return new MyWorkBook(true, workbook);
        }
    }

    /**
     * 根据Excel类型创建一个空工作薄
     *
     * @param type 1 xls 2 xlsx
     */
    private Workbook createNullWorkBook(int type) {
        Workbook workbook;
        int xlsx = 2;
        if (type == xlsx) {
            workbook = new SXSSFWorkbook();
        } else {
            workbook = new HSSFWorkbook();
        }
        return workbook;
    }

    /**
     * 创建一个sheet
     *
     * @param wb        工作薄
     * @param sheetName sheet名称
     */
    private Sheet createSheet(Workbook wb, String sheetName) {
        //判断页签是否存在
        Sheet sheet = wb.getSheet(sheetName);
        if (sheet == null) {
            //创建一个页签
            sheet = wb.createSheet(sheetName);
        }
        return sheet;
    }

    /**
     * 创建一行空行
     *
     * @param sheet       页签
     * @param rowNumber   行索引
     * @param templateRow 样式模板行
     * @return 返回创建的空行
     */
    public Row createRow(Sheet sheet, int rowNumber, Row templateRow) {
        Row row = sheet.createRow(rowNumber);
        for (int i = 0; i < templateRow.getLastCellNum(); i++) {
            //设置样式
            row.createCell(i).setCellStyle(templateRow.getCell(i).getCellStyle());
        }
        return row;
    }

    /**
     * 设置单元格值
     *
     * @param cell      单元格
     * @param filedData 填充值
     */
    private void setValue(Cell cell, Object filedData) {
        //空字段不做数据处理
        if (filedData == null) {
            return;
        }
        //TODO:需要处理其他特殊类型
        String type = filedData.getClass().getSimpleName();
        //如果数据是日期类型
        String dateTypeString = "date";
        if (dateTypeString.equalsIgnoreCase(type)) {
            cell.setCellValue((Date) filedData);
        } else {
            cell.setCellValue(filedData.toString());
        }
    }

    /**
     * 反射填充一行数据
     *
     * @param row          行对象
     * @param rowData      行数据对象
     * @param isCreateCell 是否需要创建单元格
     */
    public void fullRowData(Row row, Object rowData, boolean isCreateCell) {
        //取出所有私有字段
        Field[] declaredFields = rowData.getClass().getDeclaredFields();
        for (int i = 0; i < declaredFields.length; i++) {
            Field field = declaredFields[i];
            field.setAccessible(true);
            //如果是序列化字段，则不做数据写入
            if ("serialVersionUID".equalsIgnoreCase(field.getName())) {
                continue;
            }
            //将数据写入到单元格中
            try {
                //获取到cell
                Cell cell;
                if (isCreateCell) {
                    cell = row.createCell(i);
                } else {
                    cell = row.getCell(i);
                    if (cell == null) {
                        cell = row.createCell(i);
                    }
                }
                //设置值
                Object filedData = field.get(rowData);
                setValue(cell, filedData);
            } catch (IllegalAccessException e) {
                e.printStackTrace();
            }
            field.setAccessible(false);
        }
    }

    /**
     * 标准表格填充数据方式
     *
     * @param sheet  填充的分页
     * @param header 表头
     * @param data   表体内容
     */
    private void fullSheetData(Sheet sheet, String[] header, List<?> data) {
        //写表头
        Row rowHeader = sheet.createRow(0);
        for (int i = 0; i < header.length; i++) {
            rowHeader.createCell(i, CellType.STRING).setCellValue(header[i]);
        }

        //写表内容
        int rowNum = 1;
        for (Object one : data) {
            //创建一个新行
            Row oneRow = sheet.createRow(rowNum);
            //调用行数据填充方法
            fullRowData(oneRow, one, true);
            //行号累加
            rowNum++;
        }
    }

    /**
     * 保存工作薄
     *
     * @param wb       工作薄对象
     * @param filePath 文件路径
     * @return 保存成功返回true
     */
    private boolean saveWorkBook(Workbook wb, String filePath) {
        FileOutputStream out = null;
        try {
            out = new FileOutputStream(filePath);
            wb.write(out);
            return true;
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (out != null) {
                try {
                    wb.close();
                    out.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
        return false;
    }

    /**
     * 保存一个Excel
     *
     * @param filePath  保存文件路径
     * @param header    表头
     * @param data      数据内容列表
     * @param sheetName 页签名称
     * @return 保存成功返回true
     */
    public boolean saveData(String filePath, String[] header, List<?> data, String sheetName) {
        // 创建工作薄
        MyWorkBook workBook = createWorkBook(filePath);
        // 创建Sheet
        Sheet sheet = createSheet(workBook.getWorkbook(), sheetName);
        // 填充Sheet数据
        fullSheetData(sheet, header, data);
        // 保存表格
        if (workBook.isNull()) {
            return saveWorkBook(workBook.getWorkbook(), filePath);
        } else {
            //构建一个新路径
            String newPath = filePath.substring(0, filePath.lastIndexOf(".")) + "-" + DateTime.now().toString("yyyy-MM-dd-HH-mm-ss-S");
            String suffix = filePath.substring(filePath.lastIndexOf("."));
            newPath += suffix;
            return saveWorkBook(workBook.getWorkbook(), newPath);
        }
    }
}
