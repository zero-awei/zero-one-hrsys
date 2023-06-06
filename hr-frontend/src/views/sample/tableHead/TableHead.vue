<template>
  <TableHead
    :tableTitle="tableTitle"
    :addTitle="addTitle"
    :tableOperations="tableOperations"
    :dataitem="dataitem"
    :saveData="saveData"
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
    name: '搜索'
  },
  {
    name: '新增'
  },
  {
    name: '删除'
  }
])
//新增表单所需栏目配置
const dataitem = reactive([
  {
    label: '员工姓名',
    name: 'name',
    type: String
  },
  {
    label: '员工编号',
    name: 'ID',
    type: Array,
    //如果是选项请配置以下属性
    options: [
      {
        id: 1,
        optionData: '111'
      },
      {
        id: 2,
        optionData: '222'
      }
    ]
  },
  {
    label: '备注',
    name: 'remark',
    type: 'Text'
  }
])

const saveData = (val) => {
  //写保存数据的逻辑
}
</script>