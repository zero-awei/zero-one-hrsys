<template>
  <TableHead :tableTitle="tableTitle" :addTitle="addTitle" :tableOperations ="tableOperations" :addData="addData"/>
</template>

<script setup>
import TableHead from '@/components/table/head/TableHead.vue'
import { reactive } from 'vue'
import { stringifyQuery } from 'vue-router'
const tableTitle = ref('人员列表')
const addTitle = ref('人员列表编辑')
const tableOperations = reactive([
  {
    is:true,
    name:'新增'
  },
  {
    is:true,
    name:'导入'
  },  
])
const addData = reactive([
  {
    label:'员工姓名',
    name:'name',
    type:String,
  },
  {
    label:'员工编号',
    name:'ID',
    type:Array,
    //如果是选项请配置以下属性
    options:[
      {
        id:1,
        optionData:"111"
      },
      {
        id:2,
        optionData:"222"
      },
    ]   
  }
])
</script>