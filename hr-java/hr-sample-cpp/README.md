# 工程简介
演示声明式调用c++提供的服务

# 延伸阅读

## `hystrix`参考

```yaml
# hystrix服务熔断配置参考配置
feign:
  hystrix:
    enabled: true
# 服务熔断配置
hystrix:
  command:
    default: #配置服务降级全局超时时间
      execution:
        isolation:
          thread:
            timeoutInMilliseconds: 12000  #默认（1s即1000）
        timeout:
          #（默认true）开启超时熔断,为false将超时控制交给ribbon
          enabled: true 
      circuitBreaker: #10秒内，5次请求，失败率在50%，熔断8秒。
        requestVolumeThreshold: 5  #默认20 ，一个rolling window内最小的请求数。如果设为20， 10秒（Hystrix的滑动窗口算法）内发起了至少20次请求，失败率超过50%（errorThresholdPercentage）,从熔断开启后,不在调用该远程服务
        sleepWindowInMilliseconds: 8000  #默认5S 休眠时长
        errorThresholdPercentage: 50 #触发熔断的失败请求最小占比，默认50%
# 负载均衡配置
ribbon:
  MaxAutoRetries: 0 #（默认1次 不包括第一次）最大重试次数，当注册中心中可以找到服务，但是服务连不上时将会重试，如果注册中心中找不到服务则直接走断路器
  MaxAutoRetriesNextServer: 1 #（默认0次 不包括第一次）切换实例的重试次数
  OkToRetryOnAllOperations: false  #对所有操作请求都进行重试，如果是get则可以，如果是post，put等操作没有实现幂等的情况下是很危险的,所以设置为false
  ConnectTimeout: 3000  #（默认1s）请求连接的超时时间
  ReadTimeout: 3000 #（默认1s）请求处理的超时时间

# Hystrix与Ribbon的默认请求超时时间都是1秒
# 在接口调用的时候，两个计时器会同时读秒。所以建议配置Hystrix的超时时间要大于Ribbon的超时时间，Ribbon重试超时后，再进行熔断处理。
# OpenFeign默认开启Ribbon，开启Hystrix需要添加配置。当开启Hystrix，单独设置Hystrix的超时时间，可能会小于Ribbon的默认时间，会出现不确定的结果。
# 当 Hystrix超时时间 < Ribbon超时时间，程序会先回调进入到Hystrix的fallback方法，并继续执行下去。Ribbon会继续发送请求，直到请求完成，或达到重试次数，Ribbon的重试也就没有了意义。
# Ribbon的重试次数不包括第一次请求，如果MaxAutoRetries=1，MaxAutoRetriesNextServer=2，则最大请求次数为6 （(1+1)(2+1)）次，最大超时时间为(ConnectTimeout+ReadTimeout)*6
```

## `sentinel`配置参考

https://sentinelguard.io/zh-cn/docs/basic-api-resource-rule.html
