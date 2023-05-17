<template>
  <el-table
    ref="multipleTableRef"
    height="calc(95vh - 40px)"
    :data="tableData"
    style="width: 100%"
    table-layout="auto"
    :default-sort="{ prop: 'id', order: 'ascending' }"
    @selection-change="handleSelectionChange"
  >
    <el-table-column type="selection" fixed />
    <el-table-column
      v-for="item in xmlData"
      :key="item.id"
      :label="item.name"
      :prop="item.prop"
      width="150"
      sortable
    />
  </el-table>
</template>

<script lang="ts" setup>
import { ref } from 'vue'
import { ElTable } from 'element-plus'
//自定义数据
interface User {
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

const multipleTableRef = ref<InstanceType<typeof ElTable>>()
const multipleSelection = ref<User[]>([])
const toggleSelection = (rows?: User[]) => {
  if (rows) {
    rows.forEach((row) => {
      // TODO: improvement typing when refactor table
      // eslint-disable-next-line @typescript-eslint/ban-ts-comment
      // @ts-expect-error
      multipleTableRef.value!.toggleRowSelection(row, undefined)
    })
  } else {
    multipleTableRef.value!.clearSelection()
  }
}
const handleSelectionChange = (val: User[]) => {
  multipleSelection.value = val
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
  { id: 8, name: '出生日期', prop: 'certificateId' },
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
  }
]
</script>

<style lang="scss" scoped>
@include block(main-table) {
  background-color: red;
}
</style>
