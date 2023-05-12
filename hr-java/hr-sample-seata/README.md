# 工程简介
演示分布式远程事务管理

# 延伸阅读
## Seata相关
参考链接：https://seata.io/zh-cn/docs/overview/what-is-seata.html

### 术语

- TC (Transaction Coordinator) - 事务协调者

  维护全局和分支事务的状态，驱动全局事务提交或回滚。

- TM (Transaction Manager) - 事务管理器

  定义全局事务的范围：开始全局事务、提交或回滚全局事务。

- RM (Resource Manager) - 资源管理器

  管理分支事务处理的资源，与TC交谈以注册分支事务和报告分支事务的状态，并驱动分支事务提交或回滚。

### 整体机制

两阶段提交协议的演变：

一阶段：业务数据和回滚日志记录在同一个本地事务中提交，释放本地锁和连接资源。

二阶段：

- 提交异步化，非常快速地完成。
- 回滚通过一阶段的回滚日志进行反向补偿。

### spring-cloud使用参考
https://github.com/seata/seata-samples/blob/master/doc/quick-integration-with-spring-cloud.md
