# 工程简介
API聚合项目，基于Knife4j，聚合项目API访问接口

# 延伸阅读
参考链接：
最新版本：https://doc.xiaominfo.com/docs/middleware-sources/aggregation-introduction
v2版本：https://doc.xiaominfo.com/v2/resources/aggregation-nacos.html

授权登录或刷新登录的AfterScript设置参考示例

```javascript
// 获取登录结果
var code = ke.response.data.code;
// 如果服务端响应code是10000才执行操作
if(code==10000){
    // 获取Token
    var token = ke.response.data.data.token;
    // 获取Token前缀
    var tokenHead = ke.response.data.data.tokenHead;
    // 设置全局授权内容
    ke.global.setAllHeader("Authorization",tokenHead + token);
}
```