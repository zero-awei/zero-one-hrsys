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
const title = ref('挂职人员花名册')
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
  state: string
  //我真不知道挂职咋翻译了,先占个位
  guazhiState: string
  guazhiOrganization: string
  guazhiDepartment: string
  guazhiStartTime: string
  guazhiEndTime: string
}
const xmlData = [
  { id: 1, name: '员工编号', prop: 'id' },
  { id: 2, name: '员工姓名', prop: 'name' },
  { id: 3, name: '员工状态', prop: 'state' },
  { id: 4, name: '挂职状态', prop: 'guazhiState' },
  { id: 5, name: '挂职组织', prop: 'guazhiOrganization' },
  { id: 6, name: '挂职部门', prop: 'guazhiDepartment' },
  { id: 7, name: '挂职开始时间', prop: 'guazhiStartTime' },
  { id: 8, name: '挂职结束时间', prop: 'guazhiEndTime' }
]
const tableData: User[] = [
  {
    id: 10001,
    name: '彭于晏',
    state: '',
    guazhiState: '挂职进',
    guazhiOrganization: '上海小组',
    guazhiDepartment: '项目部',
    guazhiStartTime: '2019-4-17',
    guazhiEndTime: '2020-4-17'
  },
  {
    id: 10002,
    name: '彭于',
    state: '',
    guazhiState: '挂职进',
    guazhiOrganization: '上海小组',
    guazhiDepartment: '项目部',
    guazhiStartTime: '2019-4-17',
    guazhiEndTime: '2020-4-17'
  },
  {
    id: 10005,
    name: '彭啥的',
    state: '',
    guazhiState: '挂职进',
    guazhiOrganization: '上海小组',
    guazhiDepartment: '项目部',
    guazhiStartTime: '2019-4-17',
    guazhiEndTime: '2020-4-17'
  }
]
//test
const pagesizes = ref([1, 2, 3, 4, 5])
const pagenumber = ref(5)
</script>

<style></style>
