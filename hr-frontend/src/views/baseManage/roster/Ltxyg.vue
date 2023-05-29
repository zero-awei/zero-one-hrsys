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
const title = ref('离(退)休人员')
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
  sex: string
  age: number
  address: string
  retirePlace: string
  familyContact: string
  familyContactNumber: string
  organization: string
  department: string
  level: string
  preRetirePosition: string
  preRetireJob: string
  retireTime: string
  realRetireTime: string
  phoneNumber: string
  money: number
}

const xmlData = [
  { id: 1, name: '员工编号', prop: 'id' },
  { id: 2, name: '员工姓名', prop: 'name' },
  { id: 3, name: '性别', prop: 'sex' },
  { id: 4, name: '年龄', prop: 'age' },
  { id: 5, name: '通讯地址', prop: 'address' },
  { id: 6, name: '退休地', prop: 'retirePlace' },
  { id: 7, name: '家庭联系人', prop: 'familyContact' },
  { id: 8, name: '家庭联系人电话', prop: 'familyContactNumber' },
  { id: 9, name: '组织', prop: 'organization' },
  { id: 10, name: '部门', prop: 'department' },
  { id: 11, name: '职级', prop: 'level' },
  { id: 12, name: '退休前职务', prop: 'preRetirePosition' },
  { id: 13, name: '退休前岗位', prop: 'preRetireJob' },
  { id: 14, name: '退休时间', prop: 'retireTime' },
  { id: 15, name: '实际退休时间', prop: 'realRetireTime' },
  { id: 16, name: '手机号码', prop: 'phoneNumber' },
  { id: 17, name: '审批的养老金额', prop: 'money' }
]

const tableData: User[] = [
  {
    id: 12345,
    name: '张三',
    sex: '男',
    age: 30,
    address: 'xx区xx路xx号xx室',
    retirePlace: 'xxx',
    familyContact: '李四',
    familyContactNumber: '1231456',
    organization: '集团总部',
    department: '财务资金部',
    level: 'E3',
    preRetirePosition: '党支部书记',
    preRetireJob: '干部管理',
    retireTime: '2020-04-30',
    realRetireTime: '2020-04-30',
    phoneNumber: '12345',
    money: 12345
  },
  {
    id: 12346,
    name: '三张',
    sex: '男',
    age: 30,
    address: 'xx区xx路xx号xx室',
    retirePlace: 'xxx',
    familyContact: '李四',
    familyContactNumber: '1231456',
    organization: '集团总部',
    department: '财务资金部',
    level: 'E3',
    preRetirePosition: '党支部书记',
    preRetireJob: '干部管理',
    retireTime: '2020-04-30',
    realRetireTime: '2020-04-30',
    phoneNumber: '12345',
    money: 12345
  },
  {
    id: 12347,
    name: '里斯',
    sex: '男',
    age: 30,
    address: 'xx区xx路xx号xx室',
    retirePlace: 'xxx',
    familyContact: '李四',
    familyContactNumber: '1231456',
    organization: '集团总部',
    department: '财务资金部',
    level: 'E3',
    preRetirePosition: '党支部书记',
    preRetireJob: '干部管理',
    retireTime: '2020-04-30',
    realRetireTime: '2020-04-30',
    phoneNumber: '12345',
    money: 12345
  }
]
//test
const pagesizes = ref([1, 2, 3, 4, 5])
const pagenumber = ref(5)
</script>

<style></style>
