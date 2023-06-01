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
const title = ref('试用员工')
const options = reactive([
  {
    name: '搜索'
  },
  {
    name: '导出'
  }
])
interface User {
  //自定义数据
  id: number
  name: string
  organization: string
  department: string
  position: string
  job: string
  //时间我用的string
  comeTime: string
  expirTime: string
}
const xmlData = [
  { id: 1, name: '员工编号', prop: 'id' },
  { id: 2, name: '员工姓名', prop: 'name' },
  { id: 3, name: '组织', prop: 'organization' },
  { id: 4, name: '部门', prop: 'department' },
  { id: 5, name: '职务', prop: 'position' },
  { id: 6, name: '岗位', prop: 'job' },
  {
    id: 7,
    name: '到本单位时间',
    prop: 'comeTime'
  },
  {
    id: 8,
    name: '试用到期时间',
    prop: 'expirTime'
  }
]
const tableData: User[] = [
  {
    id: 10001,
    name: '彭于晏',
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    comeTime: '2019-03-05',
    expirTime: '2023-06-01'
  },
  {
    id: 10002,
    name: '彭于',
    organization: '集团分部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    comeTime: '2019-03-05',
    expirTime: '2022-06-01'
  },
  {
    id: 10003,
    name: '龚宇',
    organization: '集团总部',
    department: '企业部门',
    position: '规划师',
    job: '培训管理',
    comeTime: '2012-03-05',
    expirTime: '2013-06-01'
  },
  {
    id: 10004,
    name: '彭的晏',
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    comeTime: '2019-03-05',
    expirTime: '2023-06-01'
  },
  {
    id: 10005,
    name: '彭于让',
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    comeTime: '2019-03-05',
    expirTime: '2023-06-01'
  },
  {
    id: 10006,
    name: '彭发的',
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    comeTime: '2019-03-05',
    expirTime: '2023-06-01'
  }
]
//test
const pagesizes = ref([1, 2, 3, 4, 5])
const pagenumber = ref(5)
</script>

<style></style>
