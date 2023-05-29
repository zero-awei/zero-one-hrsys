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
const title = ref('离职员工')
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
  organization: string
  department: string
  level: string
  phoneNumber: string
  sex: string
  address: string
  familyContact: string
  familyContactNumber: string
}
const xmlData = [
  { id: 1, name: '员工编号', prop: 'id' },
  { id: 2, name: '员工姓名', prop: 'name' },
  { id: 3, name: '组织', prop: 'organization' },
  { id: 4, name: '部门', prop: 'department' },
  { id: 5, name: '职级', prop: 'level' },
  { id: 6, name: '手机号码', prop: 'phoneNumber' },
  { id: 7, name: '性别', prop: 'sex' },
  { id: 8, name: '通讯地址', prop: 'address' },
  { id: 9, name: '家庭联系人', prop: 'familyContact' },
  { id: 10, name: '家庭联系人电话', prop: 'familyContactNumber' }
]
const tableData: User[] = [
  {
    id: 10001,
    name: '彭于晏',
    organization: '集团总部',
    department: '企业部门',
    level: 'E3',
    phoneNumber: '123454',
    sex: '男',
    address: 'xxxx',
    familyContact: '张三',
    familyContactNumber: '123455'
  },
  {
    id: 10002,
    name: '彭于',
    organization: '集团总部',
    department: '企业部门',
    level: 'E3',
    phoneNumber: '123454',
    sex: '男',
    address: 'xxxx',
    familyContact: '张三',
    familyContactNumber: '123455'
  },
  {
    id: 10004,
    name: '彭三',
    organization: '集团总部',
    department: '企业部门',
    level: 'E3',
    phoneNumber: '123454',
    sex: '男',
    address: 'xxxx',
    familyContact: '张三',
    familyContactNumber: '123455'
  }
]
//test
const pagesizes = ref([1, 2, 3, 4, 5])
const pagenumber = ref(5)
</script>

<style></style>
