<template>
  <!-- 演示案例 -->
  <!-- 传入 表格设计数据 和 表格主体数据  -->
  <MainTable :tableData="tableData" :xmlData="xmlData"></MainTable>
</template>

<script lang="ts" setup>
import MainTable from '@/components/MainTable.vue'
interface User {
  //自定义数据
  id: number
  name: string
  age: number
  organization: string
  department: string
  position: string
  job: string
  certificateId: number
  phoneNumber: number
  state: string
}

// 定义表单数据
const xmlData = [
  { id: 1, name: '员工编号', prop: 'id' },
  { id: 2, name: '员工姓名', prop: 'name' },
  { id: 3, name: '组织', prop: 'organization' },
  { id: 4, name: '部门', prop: 'department' },
  { id: 5, name: '职务', prop: 'position' },
  { id: 6, name: '岗位', prop: 'job' },
  { id: 7, name: '证件号码', prop: 'certificateId' },
  { id: 8, name: '出生日期', prop: 'dateOfbrith' },
  { id: 9, name: '年龄', prop: 'age' },
  { id: 10, name: '手机号码', prop: 'phoneNumber' },
  { id: 11, name: '员工状态', prop: 'state' }
]
// 注入表格数据
const tableData: User[] = [
  {
    id: 10001,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10002,
    name: '甄子丹',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10003,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10004,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10005,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10006,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10007,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10008,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10009,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10010,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10001,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10002,
    name: '甄子丹',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10003,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10004,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10005,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10006,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10007,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10008,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10009,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10010,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10001,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10002,
    name: '甄子丹',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10003,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10004,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10005,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10006,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10007,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10008,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10009,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10010,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10001,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10002,
    name: '甄子丹',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10003,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10004,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10005,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10006,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10007,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10008,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10009,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10010,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10001,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10002,
    name: '甄子丹',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10003,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10004,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10005,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10006,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10007,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10008,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10009,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  },
  {
    id: 10010,
    name: '彭于晏',
    age: 26,
    organization: '集团总部',
    department: '企业部门',
    position: '总规划师',
    job: '培训管理',
    certificateId: 140821199103011618,
    phoneNumber: 15035052120,
    state: '在职'
  }
]
</script>

<style lang="scss" scoped></style>
