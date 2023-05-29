<template>
  <div>
    <TableHead :tableTitle="title" :tableOperations="options"> </TableHead>
    <MainTable :xml-data="xmlData" :table-data="tableData"></MainTable>
    <Pagination :pageSizes="pagesizes" :total="pagenumber" />
  </div>
</template>

<script lang="ts" setup>
import TableHead from '@/components/table/head/TableHead.vue'
import Pagination from '@/components/pagination/Pagination.vue'
import MainTable from '@/components/MainTable.vue'
import { ref, reactive } from 'vue'
const title = ref('借调人员花名册')
const options = reactive([
  {
    name: '搜索'
  },
  {
    name: '导出'
  },
  {
    name: '过滤'
  }
])
interface User {
  //自定义数据
  id: number
  name: string
  originalOrganization: string
  originalDepartment: string
  originalPosition: string
  originalJob: string
  newOrganization: string
  newDepartment: string
  newPosition: string
  newJob: string
  rentState: string
  rentStartTime: string
  rentEndTime: string
}
const xmlData = [
  { id: 1, name: '员工编号', prop: 'id' },
  { id: 2, name: '员工姓名', prop: 'name' },
  { id: 3, name: '原组织', prop: 'originalOrganization' },
  { id: 4, name: '原部门', prop: 'originalDepartment' },
  { id: 5, name: '原职务', prop: 'originalPosition' },
  { id: 6, name: '原岗位', prop: 'originalJob' },
  { id: 7, name: '新组织', prop: 'newOrganization' },
  { id: 8, name: '新部门', prop: 'newDepartment' },
  { id: 9, name: '新职务', prop: 'newPosition' },
  { id: 10, name: '新岗位', prop: 'newJob' },
  { id: 11, name: '借调状态', prop: 'rentState' },
  { id: 12, name: '借调开始时间', prop: 'rentStartTime' },
  { id: 13, name: '借调结束时间', prop: 'rentEndTime' }
]
const tableData: User[] = [
  {
    id: 10001,
    name: '彭于晏',
    originalOrganization: '山东公司',
    originalDepartment: '人力资源部',
    originalPosition: '助理总经理',
    originalJob: '工会主席',
    newOrganization: 'xxx',
    newDepartment: '市场部',
    newPosition: '部门经理',
    newJob: '薪资专员',
    rentState: '借调中',
    rentStartTime: '2023-05-24',
    rentEndTime: '2023-05-26'
  },
  {
    id: 10002,
    name: '彭于',
    originalOrganization: '山东公司',
    originalDepartment: '人力资源部',
    originalPosition: '助理总经理',
    originalJob: '工会主席',
    newOrganization: 'xxx',
    newDepartment: '市场部',
    newPosition: '部门经理',
    newJob: '薪资专员',
    rentState: '借调中',
    rentStartTime: '2023-05-24',
    rentEndTime: '2023-05-26'
  },
  {
    id: 10004,
    name: '彭啥的',
    originalOrganization: '山东公司',
    originalDepartment: '人力资源部',
    originalPosition: '助理总经理',
    originalJob: '工会主席',
    newOrganization: 'xxx',
    newDepartment: '市场部',
    newPosition: '部门经理',
    newJob: '薪资专员',
    rentState: '借调中',
    rentStartTime: '2023-05-24',
    rentEndTime: '2023-05-26'
  }
]
//test
const pagesizes = ref([1, 2, 3, 4, 5])
const pagenumber = ref(5)
</script>

<style></style>
