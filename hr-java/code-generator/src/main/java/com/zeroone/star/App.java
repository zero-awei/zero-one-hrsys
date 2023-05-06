package com.zeroone.star;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.generator.FastAutoGenerator;
import com.baomidou.mybatisplus.generator.config.OutputFile;
import com.baomidou.mybatisplus.generator.fill.Column;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.ResourceBundle;

/**
 * <p>
 * 描述：代码生成程序入口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
public class App {
    /**
     * 处理 all 情况
     *
     * @param tables 表名字符串
     * @return 处理结果
     */
    private static List<String> getTables(String tables) {
        return "all".equals(tables) ? Collections.emptyList() : Arrays.asList(tables.split(","));
    }

    public static void main(String[] args) {
        ResourceBundle res = ResourceBundle.getBundle("database");
        FastAutoGenerator.create(res.getString("db.url"), res.getString("db.username"), res.getString("db.password"))
                // 全局配置
                .globalConfig((scanner, builder) -> builder
                        .author(scanner.apply("请输入作者名称："))
                        .fileOverride()     //允许重新文件
                        .disableOpenDir()   //禁止生成成功打开文件夹
                        .outputDir(res.getString("g.output.dir")) //设置输出路径
                )
                // 包配置
                .packageConfig((scanner, builder) -> builder
                        .parent(res.getString("pkg.name"))
                        .moduleName(scanner.apply("输入模块名称："))
                        .pathInfo(Collections.singletonMap(OutputFile.mapperXml, res.getString("g.output.dir") + "\\..\\resources\\" + res.getString("pkg.xml.dir")))
                )
                // 策略配置
                .strategyConfig((scanner, builder) -> builder
                        .addInclude(getTables(scanner.apply("请输入表名，多个英文逗号分隔，所有输入all：")))
                        .controllerBuilder().enableRestStyle().enableHyphenStyle()
                        .mapperBuilder().enableMapperAnnotation()
                        .entityBuilder().enableLombok().addTableFills(new Column("create_time", FieldFill.INSERT))
                        .build()
                )
                .execute();
    }
}
