<template>
  <Qualification class="qua" :title="title" :data="data"></Qualification>
</template>

<script setup>
import Qualification from '@/components/CareerQualifications.vue'

let title = ref('职业资格')
const data = reactive([
  {
    name: '软件工程师',
    val: 30, // 宽度百分比
    color: 'skyblue' // 颜色
  },
  {
    name: 'java工程师',
    val: 20,
    color: 'pink'
  },
  {
    name: 'java工程师',
    val: 50,
    color: 'pink'
  },
  {
    name: 'java工程师',
    val: 100,
    color: 'pink'
  }
])
</script>

<style lang="scss" scoped>
.qua {
  width: 500px;
}
</style>
