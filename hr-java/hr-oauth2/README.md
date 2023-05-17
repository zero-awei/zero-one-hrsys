# 工程简介

`OAuth2`认证服务，负责对登录用户进行认证，整合`Spring Security + OAuth2`

# 延伸阅读

## 一、`RSA`证书

### 1 生成证书

首先通过终端进入到`resources`目录，然后执行证书生成命令。

```sh
keytool -genkeypair -alias 01star -keyalg RSA -keypass 123456 -keystore jwt.jks -storepass 123456 -validity 3650
keytool -importkeystore -srckeystore jwt.jks -destkeystore jwt.jks -deststoretype pkcs12
```

> **参数帮助说明**
>
> ```sh
> keytool密钥和证书管理工具
> 命令:
> -certreq            生成证书请求
> -changealias        更改条目的别名
> -delete             删除条目
> -exportcert         导出证书
> -genkeypair         生成密钥对
> -genseckey          生成密钥
> -gencert            根据证书请求生成证书
> -importcert         导入证书或证书链
> -importpass         导入口令
> -importkeystore     从其他密钥库导入一个或所有条目
> -keypasswd          更改条目的密钥口令
> -list               列出密钥库中的条目
> -printcert          打印证书内容
> -printcertreq       打印证书请求的内容
> -printcrl           打印 CRL 文件的内容
> -storepasswd        更改密钥库的存储口令
> 使用 "keytool -command_name -help" 获取 command_name 的用法
> 
> keytool -genkeypair [OPTION]...
> 生成密钥对选项: 
> -alias <alias>                  要处理的条目的别名 
> -keyalg <keyalg>                密钥算法名称 
> -keysize <keysize>              密钥位大小 
> -sigalg <sigalg>                签名算法名称 
> -destalias <destalias>          目标别名 
> -dname <dname>                  唯一判别名 
> -startdate <startdate>          证书有效期开始日期/时间 
> -ext <value>                    X.509 扩展 
> -validity <valDays>             有效天数 
> -keypass <arg>                  密钥口令 
> -keystore <keystore>            密钥库名称 
> -storepass <arg>                密钥库口令 
> -storetype <storetype>          密钥库类型 
> -providername <providername>    提供方名称 
> -providerclass <providerclass>  提供方类名 
> -providerarg <arg>              提供方参数 
> -providerpath <pathlist>        提供方类路径 
> -v                              详细输出 
> -protected                      通过受保护的机制的口令使用 
> "keytool -help" 获取所有可用命令
> ```

### 2 提取公钥

通过`openssl`可以提取PUBLIC KEY格式，windows下需要安装 `openssl`

http://slproweb.com/products/Win32OpenSSL.html

```sh
keytool -list -rfc --keystore jwt.jks | openssl x509 -inform pem -pubkey
```

提取结果

```
-----BEGIN PUBLIC KEY-----
MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA2CUog6kdKUOlOtdOHFcs
ts0KHt5eg8UPF6Yj/jte7jgxOWsYB571rdMzTDIYo1UIaYVOJcd3oio9QlebUZD7
O4GL8oJmj9rNCVk60xfx3vhYISzdHbwQhUUgx+YDmDr5UJV/D/uhCdFKziTUBMjD
otSQXvCsbWIMGGEFbPXKe9VRmgqtjdNfWvjMa7spQwiy0gj7GeOUiIttkVZna6qF
FZRSRAxp3NJ9ELbcW7Kd9u5IFzrvxXNiYPOtIiw+zqJTYsSXUJTI7YQAXy9zqGtT
7QUFUjxUf+7b1DELpGZPmwGd5Jzj+zfTNsS3DRNuPQJPkPbpUo1qCsU55sXgcNrf
zwIDAQAB
-----END PUBLIC KEY-----

-----BEGIN CERTIFICATE-----
MIIDYzCCAkugAwIBAgIEZ/7xkDANBgkqhkiG9w0BAQsFADBiMQswCQYDVQQGEwJj
bjEQMA4GA1UECBMHc2ljaHVhbjEQMA4GA1UEBxMHY2hlbmdkdTEPMA0GA1UEChMG
MDFzdGFyMQ8wDQYDVQQLEwYwMXN0YXIxDTALBgNVBAMTBGF3ZWkwHhcNMjExMjI5
MDE0NDIzWhcNMzExMjI3MDE0NDIzWjBiMQswCQYDVQQGEwJjbjEQMA4GA1UECBMH
c2ljaHVhbjEQMA4GA1UEBxMHY2hlbmdkdTEPMA0GA1UEChMGMDFzdGFyMQ8wDQYD
VQQLEwYwMXN0YXIxDTALBgNVBAMTBGF3ZWkwggEiMA0GCSqGSIb3DQEBAQUAA4IB
DwAwggEKAoIBAQDYJSiDqR0pQ6U6104cVyy2zQoe3l6DxQ8XpiP+O17uODE5axgH
nvWt0zNMMhijVQhphU4lx3eiKj1CV5tRkPs7gYvygmaP2s0JWTrTF/He+FghLN0d
vBCFRSDH5gOYOvlQlX8P+6EJ0UrOJNQEyMOi1JBe8KxtYgwYYQVs9cp71VGaCq2N
019a+MxruylDCLLSCPsZ45SIi22RVmdrqoUVlFJEDGnc0n0Qttxbsp327kgXOu/F
c2Jg860iLD7OolNixJdQlMjthABfL3Ooa1PtBQVSPFR/7tvUMQukZk+bAZ3knOP7
N9M2xLcNE249Ak+Q9ulSjWoKxTnmxeBw2t/PAgMBAAGjITAfMB0GA1UdDgQWBBRo
czTTqtgEoqi6ryQAif2qJFl2lDANBgkqhkiG9w0BAQsFAAOCAQEAqhAO1nB2UHoH
11stZ5uw72vH+vGmCoSP/bXQwKvBxcWEdpjw6xsZSGyojheVUCA0yfOy3KY8gZkl
jjTdpH0MtCKBASdjCHfmmvzq+DOXI2Xlq7eNvNU2AwKolwByVUEUX7bcIrRshXE0
Mzcgwb4YigSgpnQ5dm+nWq6pDcBDQ1Xi94bSNtaFct08jHEStv9LVP1+icrzXBGr
Ji2o4ODDn6PCbxqmwq5b3y1vl/vcU50xP+yjrTqT6nkJLTxMvaYc/s+6X3QYz4SB
QY2fIHOY6vHVNnAyRHFdOoFFXkbHzSDeWZ72Jf23gCaBISRrYaOGsWtmijgf9idH
snHq0k6a1A==
-----END CERTIFICATE-----
```

### 3 提取私钥

需要把证书先转成`pfx`格式

```sh
keytool -v -importkeystore -srckeystore jwt.jks -srcstoretype jks -srcstorepass 123456 -destkeystore jwt.pfx -deststoretype pkcs12 -deststorepass 123456 -destkeypass 123456
```

提取私钥

```sh
#显示在屏幕上
openssl pkcs12 -in jwt.pfx -nocerts -nodes

#输出到文件
openssl pkcs12 -in jwt.pfx -nocerts -nodes -out jwt.key
```

提取格式如

```
-----BEGIN PRIVATE KEY-----
MIIEvQIBADANBgkqhkiG9w0BAQEFAASCBKcwggSjAgEAAoIBAQDYJSiDqR0pQ6U6
104cVyy2zQoe3l6DxQ8XpiP+O17uODE5axgHnvWt0zNMMhijVQhphU4lx3eiKj1C
V5tRkPs7gYvygmaP2s0JWTrTF/He+FghLN0dvBCFRSDH5gOYOvlQlX8P+6EJ0UrO
JNQEyMOi1JBe8KxtYgwYYQVs9cp71VGaCq2N019a+MxruylDCLLSCPsZ45SIi22R
VmdrqoUVlFJEDGnc0n0Qttxbsp327kgXOu/Fc2Jg860iLD7OolNixJdQlMjthABf
L3Ooa1PtBQVSPFR/7tvUMQukZk+bAZ3knOP7N9M2xLcNE249Ak+Q9ulSjWoKxTnm
xeBw2t/PAgMBAAECggEADHXH6h8boT9XDRdQV23nE/qp9LGY/Tuk7RYUyRkfFdiD
be3wiq/tNcIRGPliVjgWrg6TPLZM/To2IdbvCzqyYPHM4YQG6ZARddKBA55DwTjL
y83MSWSIB0a+5wcpeeMccDrOAlvdIrW//DY/Sq9QJ9jdIbv6FKwsSlN9fpSEwbKl
TDqwZJCyc5KBKq7r6NixO/ksATi1uaQUfJT5b4sakGKUN5I7MwAjST4em7Ze8VVc
HGt1ClaTgLxKfPMurd0Ec+8o/3ex/PkU7Wx8AHqAj/IQsLdNB2arHePpcQVzHjsb
u4+zJSrtxOzrZlC/qfPObh8+o/i72K556ZfcEFjb8QKBgQDt2qD5sKn592+xtGXX
rzv/8G1CdE6Zy4WBUl33gov2rbGvmkrAeDGWV7dgTW0fPI9oXhV4Ioc7q61cDp8C
U9FDjDNpEEhUextq4VFjJWQ2tUvigyTkMFT7dEg1j35jbMGmvNh9jWQzdeM3Rheb
Q8VVGbZ5i2z4iGpfrDfStUeiiwKBgQDooow36Y5KZtvbnkF+C0nqQ7LC63ZsSBTS
UQgFWw5sBJssv9DsZIm1Ke14aHZftrDm67mg+/xsrw3+DZxwlaui8zA4PLpmTrGj
AnJ/2F9En8LZtb/ove+gXuQjZrNUsHh6+OpMWaEC1Flp3+jaPoaKZPp0ta/WYHPi
OEQ3uvh0TQKBgH0FvjeAtNe/R+aQfDey1EbjiYq0t9v/Ll2bfejrpcYz5oH3B/PD
Oc1crfbgu8r/eiHR0lcjTxH+W1FYHhyLEiP/Pcar2FkPnInBhZYnwVVAVnLpnCqV
fRXvOUVt93EraV7LRMA54cFq5dPX8/CY3tCsg03AC7dXfRJs46rNvqmhAoGACyR1
+Nub8B5bG3rKAkKCKNFTR5jFlEwjiytMag1BdJUH5a3OUPRD0ESQ1jqSqOT0NitG
Odq37XC5B9kZDB9vGB/zyE3IU8wjH/6nA06WyY+pYoodBgXK63CAFt39auoE60bu
2fdVCfCn07Vgzss94HUTtfFZ2bfG9SfixJSU/+UCgYEAyW1Si7qQRiNUSJWU8Jae
yFWOL1mvZRpXPUlg70H4wARoJjK6XgNKcE6GWbOedNtyiVJ7b07bmf9YJX2NWOzE
913vLOeLSlJeJAoQHEoYCM0nnOEcfUMiuOx59R4zk4RzSC64uK9PeguGSS6RaQwQ
8aj6l5u1SVtUNRb+ZjPCU8c=
-----END PRIVATE KEY-----
```

## 二、数据库脚本

```sql
DROP TABLE IF EXISTS `user_role`;
DROP TABLE IF EXISTS `role_menu`;
DROP TABLE IF EXISTS `role`;
DROP TABLE IF EXISTS `user`;
DROP TABLE IF EXISTS `menu`;

CREATE TABLE `user` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '用户编号',
  `username` varchar(32) DEFAULT NULL COMMENT '账户名',
  `password` varchar(256) DEFAULT NULL COMMENT '密码',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='用户表';

CREATE TABLE `role` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '唯一ID',
  `name` varchar(32) DEFAULT NULL COMMENT '角色名',
  `keyword` varchar(64) DEFAULT NULL COMMENT '关键词',
  `description` varchar(128) DEFAULT NULL COMMENT '角色描述',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='角色表';

CREATE TABLE `user_role` (
  `user_id` int(11) NOT NULL COMMENT '用户ID',
  `role_id` int(11) NOT NULL COMMENT '角色ID',
  PRIMARY KEY (`user_id`,`role_id`),
  CONSTRAINT `FK_Reference_u_user` FOREIGN KEY (`user_id`) REFERENCES `user` (`id`),
  CONSTRAINT `FK_Reference_u_role` FOREIGN KEY (`role_id`) REFERENCES `role` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='用户角色';

CREATE TABLE `menu` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '菜单编号',
  `name` varchar(128) DEFAULT NULL COMMENT '菜单名',
  `link_url` varchar(128) DEFAULT NULL COMMENT '链接地址',
  `path` varchar(128) DEFAULT NULL COMMENT '路由地址',
  `priority` int(11) DEFAULT NULL COMMENT '显示优先级别',
  `icon` varchar(64) DEFAULT NULL COMMENT '图标',
  `description` varchar(128) DEFAULT NULL COMMENT '描述',
  `parent_menu_id` int(11) DEFAULT NULL COMMENT '父级菜单编号',
  `level` int(11) DEFAULT NULL COMMENT '层次级别',
  `is_enable` tinyint(4) DEFAULT '1' COMMENT '是否启用 0 禁用 1 启用',
  PRIMARY KEY (`id`),
  CONSTRAINT `FK_Reference_menu` FOREIGN KEY (`parent_menu_id`) REFERENCES `menu` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='菜单';

CREATE TABLE `role_menu` (
  `role_id` int(11) NOT NULL COMMENT '角色ID',
  `menu_id` int(11) NOT NULL COMMENT '菜单ID',
  PRIMARY KEY (`role_id`,`menu_id`),
  CONSTRAINT `FK_Reference_r_menu` FOREIGN KEY (`menu_id`) REFERENCES `menu` (`id`),
  CONSTRAINT `FK_Reference_r_role` FOREIGN KEY (`role_id`) REFERENCES `role` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='角色菜单关系表';

INSERT INTO `user` VALUES ('1', 'admin', '$2a$10$K7U.Xolbbz3fGsAzpIawmeQuTWt/W0TXA8DpugqRwWsE0PeRSi1Vu');
INSERT INTO `user` VALUES ('2', 'test', '$2a$10$K7U.Xolbbz3fGsAzpIawmeQuTWt/W0TXA8DpugqRwWsE0PeRSi1Vu');
INSERT INTO `role` VALUES ('1', '超级管理员', 'SUPER_ADMIN', null);
INSERT INTO `role` VALUES ('2', '普通管理员', 'ADMIN', null);
INSERT INTO `user_role` VALUES ('1', '1');
INSERT INTO `user_role` VALUES ('2', '2');

INSERT INTO `menu` VALUES ('1', '示例查询', '/cpp/query', '2', '2', 'fa-user-md', null, null, '1', '1');
INSERT INTO `menu` VALUES ('2', '示例添加', '/cpp/add', '/2-1', '1', null, null, '1', '2', '1');
INSERT INTO `menu` VALUES ('3', '示例修改', '/cpp/modify', '/2-2', '2', null, null, '1', '2', '1');
INSERT INTO `menu` VALUES ('4', '示例删除', '/cpp/delete', '/2-3', '3', null, null, '1', '2', '1');
INSERT INTO `menu` VALUES ('5', '示例JSON', '/cpp/json', '/2-3', '3', null, null, '1', '2', '1');
INSERT INTO `role_menu` VALUES ('1', '1');
INSERT INTO `role_menu` VALUES ('1', '2');
INSERT INTO `role_menu` VALUES ('1', '3');
INSERT INTO `role_menu` VALUES ('1', '4');
INSERT INTO `role_menu` VALUES ('1', '5');
INSERT INTO `role_menu` VALUES ('2', '1');
INSERT INTO `role_menu` VALUES ('2', '5');
```

