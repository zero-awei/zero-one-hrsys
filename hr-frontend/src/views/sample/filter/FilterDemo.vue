<template>
  <div class="filter">
    <Filter :data="data"></Filter>
  </div>
</template>

<script setup>
import Filter from '@/components/filter/Filter.vue'

// 传入给过滤器的数据示例
// 说明：
// 这里采用的是按照表单类型设置数据
// input中的属性全部为输入类型的表单元素
// select中的属性全部为下拉列表类型的表单元素
const data = reactive({
  employeeName: {
    name: '员工姓名',
    type: 'input'
  },
  employeeNum: {
    name: '员工编号',
    type: 'input'
  },
  employeeStatus: {
    name: '员工状态',
    type: 'select',
    options: [
      {
        value: 'on',
        label: '在职'
      },
      {
        value: 'apprenticeship',
        label: '见习'
      },
      {
        value: 'probation',
        label: '试用'
      },
      {
        value: 're-employ',
        label: '返聘'
      },
      {
        value: 'unemployed',
        label: '待岗'
      },
      {
        value: 'dismiss',
        label: '解聘'
      },
      {
        value: 'off',
        label: '离职'
      },
      {
        value: 'retire',
        label: '退休'
      },
      {
        value: 'discharge',
        label: '离休'
      },
      {
        value: 'retreat',
        label: '内退'
      },
      {
        value: 'sick',
        label: '病休'
      },
      {
        value: 'adjusted',
        label: '可调配'
      },
      {
        value: 'died',
        label: '身故'
      },
      {
        value: 'co-management',
        label: '共同管理'
      }
    ]
  },
  Id: {
    name: '证件号码',
    type: 'input'
  },
  organization: {
    name: '组织',
    type: 'input'
  },
  department: {
    name: '部门',
    type: 'input'
  }
})

// 全局事件总线
const mitt = getCurrentInstance().appContext.config.globalProperties.$bus

// 根据过滤器结果，发送请求
function requestRes(data) {
  // 调用请求接口
  // ...
  // 输出过滤器结果
  console.log(`output->data`, data)
}
mitt.on('search', requestRes)
</script>

<style lang="scss" scoped>
.filter {
  color: purple;
}
</style>
