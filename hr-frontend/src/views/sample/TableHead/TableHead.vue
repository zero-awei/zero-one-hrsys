<template>
  <TableHead
    :tableTitle="tableTitle"
    :addTitle="addTitle"
    :tableOperations="tableOperations"
    :addData="addData"
  />
</template>

<script setup>
import TableHead from '@/components/table/head/TableHead.vue'
import { reactive } from 'vue'
import { stringifyQuery } from 'vue-router'
//表格表名
const tableTitle = ref('人员列表')
//新增表单的表名
const addTitle = ref('人员列表编辑')
//功能按键需求配置
const tableOperations = reactive([
  {
    name: '新增'
  },
  {
])
//新增表单所需栏目配置
  {
    type:String,
  },
  {
    type:Array,
    //如果是选项请配置以下属性
    options: [
      {
        optionData:"111"
      },
      {
    ]
  },
  {
  },
])
const saveData = (val)=>{
  //写保存数据的逻辑
}
</script>