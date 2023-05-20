<template>
  <TableHead :tableTitle="tableTitle" :tableOperations ="tableOperations" :addData="addData"/>
</template>

<script setup>
import TableHead from '@/components/table/head/TableHead.vue'
import { reactive } from 'vue'
import { stringifyQuery } from 'vue-router'
const tableTitle = ref('人员列表')
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
    name:'name'
  },
])
</script>