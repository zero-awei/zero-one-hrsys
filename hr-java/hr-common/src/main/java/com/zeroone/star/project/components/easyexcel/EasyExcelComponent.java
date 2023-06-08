package com.zeroone.star.project.components.easyexcel;

import com.alibaba.excel.EasyExcel;
import com.alibaba.excel.ExcelWriter;
import com.alibaba.excel.write.builder.ExcelWriterBuilder;
import com.alibaba.excel.write.metadata.WriteSheet;
import org.springframework.stereotype.Component;

import java.io.IOException;
import java.io.OutputStream;
import java.util.List;

/**
 * <p>
 * 描述：EasyExcel操作组件
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
@Component
public class EasyExcelComponent {
    /**
     * 定义每个页签存储的数据量
     */
    private static final int MAX_COUNT_PER_SHEET = 5000;

    /**
     * 生成 Excel
     *
     * @param path      Excel 存储路径
     * @param sheetName sheet名称
     * @param clazz     存储的数据类型
     * @param dataList  存储数据集合
     * @param <T>       生成元素实体类类型
     */
    public <T> void generateExcel(String path, String sheetName, Class<T> clazz, List<T> dataList) {
        EasyExcel.write(path, clazz).sheet(sheetName).doWrite(dataList);
    }

    /**
     * 解析Excel
     *
     * @param path  解析的Excel的路径
     * @param clazz 存储的数据类型
     * @param <T>   解析元素实体类类型
     * @return 解析后的数据集合
     */
    public <T> List<T> parseExcel(String path, Class<T> clazz) {
        ExcelReadListener<T> listener = new ExcelReadListener<>();
        //sheet()方法表示读取所有的sheet
        //doRead() 表示表示执行读取动作
        EasyExcel.read(path, clazz, listener).sheet().doRead();
        return listener.getDataList();
    }

    /**
     * 导出到输出流
     *
     * @param sheetName sheet名称
     * @param os        输出流
     * @param clazz     导出数据类型
     * @param dataList  导出的数据集
     * @param <T>       生成元素实体类类型
     * @throws IOException IO异常
     */
    public <T> void export(String sheetName, OutputStream os, Class<T> clazz, List<T> dataList) throws IOException {
        ExcelWriterBuilder builder = EasyExcel.write(os, clazz);
        ExcelWriter writer = builder.build();
        //计算总页数
        int sheetCount = dataList.size() / MAX_COUNT_PER_SHEET;
        sheetCount = dataList.size() % MAX_COUNT_PER_SHEET == 0 ? sheetCount : sheetCount + 1;
        //循环构建分页
        for (int i = 0; i < sheetCount; i++) {
            //创建一个页签
            WriteSheet sheet = new WriteSheet();
            sheet.setSheetNo(i);
            sheet.setSheetName(sheetName + (i + 1));
            //设置数据起始位置
            int start = i * MAX_COUNT_PER_SHEET;
            int end = (i + 1) * MAX_COUNT_PER_SHEET;
            end = Math.min(end, dataList.size());
            //写入数据到页签
            writer.write(dataList.subList(start, end), sheet);
        }
        writer.finish();
        os.close();
    }
}
