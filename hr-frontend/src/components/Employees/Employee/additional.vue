<template>
  <div class="employee">
    <div class="head">补充信息</div>
    <div class="box">
      <div>
        <div class="right">户口类型</div>
        <div class="left">{{ nodeType }}</div>
        <br />
        <div class="right">健康状况</div>
        <div class="left">{{ health }}</div>
        <br />
        <div class="right">有独生子女证</div>
        <div class="left">{{ onlyChild }}</div>
        <br />
        <div class="right">员工状态</div>
        <div class="left">{{ employeeStatus }}</div>
      </div>
      <div>
        <div class="right">户籍所在地</div>
        <div class="left">{{ residence }}</div>
        <br />
        <div class="right">爱好特长</div>
        <div class="left">{{ hobby }}</div>
        <br />
        <div class="right">通讯地址</div>
        <div class="left">{{ mailAddress }}</div>
        <br />
        <div class="right">列入黑名单</div>
        <div class="left">{{ blacklist }}</div>
      </div>
      <div>
        <div class="right">出生地</div>
        <div class="left">{{ birthplace }}</div>
        <br />
        <div class="right">血型</div>
        <div class="left">{{ blood }}</div>
        <br />
        <div class="right">入职渠道</div>
        <div class="left">{{ onboardingChannels }}</div>
      </div>
    </div>
  </div>
</template>
<script>
export default {
  data() {
    return {
      nodeType: '农村户口',
      residence: '北京市',
      health: '健康',
      onlyChild: '有',
      onboardingChannels: '校招',
      employeeStatus: '在职',
      hobby: '唱、跳、rep、篮球',
      mailAddress: '北京市丰台区',
      blacklist: '否',
      birthplace: '美国',
      blood: '0型'
    }
  }
}
</script>
<style>
.head {
  margin: 8px;
  color: #000;
  height: 50px;
  line-height: 50px;
  font-size: 16px;
  font-weight: 600;
  border-bottom: 1px solid #ebeef5;
}
.box {
  display: flex;
  height: 200px;
}

.box div {
  flex: 1;
  height: 50px;
}
.left {
  padding-left: 8px;
  float: left;
  width: 70%;
  text-align: left;
}
.right {
  float: left;
  width: 30%;
  text-align: right;
}
</style>
