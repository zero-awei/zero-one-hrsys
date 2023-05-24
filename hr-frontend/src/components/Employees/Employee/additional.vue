<template>
  <div class="employee">
    <div class="head">补充信息</div>
    <div class="box">
      <div v-for="n in val" :key="n">
        <div v-for="k in 4" :key="k">
          <div class="right">
            {{ Object.values(data)[(n - 1) * 4 + k - 1]?.title }}
          </div>
          <div class="left">
            {{ Object.values(data)[(n - 1) * 4 + k - 1]?.val }}
          </div>
          <br />
        </div>
      </div>
    </div>
  </div>
</template>
<script>
export default {
  data() {
    return {
      data: {
        nodeType: { title: '户口类型', val: '农村户口', id: 0 },
        nodeType1: { title: '户籍所在地', val: '北京市', id: 1 },
        nodeType2: { title: '出生地', val: '北京市丰台区', id: 2 },
        nodeType3: { title: '健康状况', val: '健康', id: 3 },
        nodeType4: { title: '爱好特长', val: '唱、跳、rep、篮球', id: 4 },
        nodeType5: { title: '血型', val: '0型', id: 5 },
        nodeType6: { title: '有独生子女证', val: '有', id: 5 },
        nodeType7: { title: '通讯地址', val: '北京市丰台区', id: 5 },
        nodeType8: { title: '入职渠道', val: '校招', id: 5 },
        nodeType9: { title: '员工状态', val: '在职', id: 5 },
        nodeType10: { title: '列入黑名单', val: '否', id: 5 }

        // residence: '北京市',
        // health: '健康',
        // onlyChild: '有',
        // onboardingChannels: '校招',
        // employeeStatus: '在职',
        // hobby: '唱、跳、rep、篮球',
        // mailAddress: '北京市丰台区',
        // blacklist: '否',
        // birthplace: '美国',
        // blood: '0型'
      }
    }
  },
  computed: {
    val() {
      return Math.ceil(Object.values(this.data).length / 4)
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
