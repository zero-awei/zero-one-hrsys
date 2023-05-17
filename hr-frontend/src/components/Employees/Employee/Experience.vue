<template>
  <div style="width: 100%">
    <div class="head">工作履历</div>
    <el-table
      :data="tableData"
      table-layout="auto"
      style="padding-left: 30px"
      :cell-style="{ textAlign: 'center' }"
      :header-cell-style="{ 'text-align': 'center', color: '#000' }"
    >
      <el-table-column type="selection" width="34px" />
      <el-table-column
        width="150px"
        prop="employmentDate"
        label="任职开始时间"
        sortable
      />
      <el-table-column
        width="150px"
        prop="endOfOffice"
        label="任职结束时间"
        sortable
      />
      <el-table-column
        width="150px"
        prop="workUnit"
        label="工作单位"
        sortable
      />
      <el-table-column width="150px" prop="department" label="部门" sortable />
      <el-table-column width="150px" prop="post" label="岗位" sortable />
      <el-table-column width="150px" prop="grade" label="职级" sortable />
      <el-table-column />
    </el-table>
  </div>
</template>

<script lang="ts" setup>
interface User {
  employmentDate: string
  endOfOffice: string
  workUnit: string
  department: string
  post: string
  grade: string
}

const tableData: User[] = [
  {
    employmentDate: '2018-05-03',
    endOfOffice: '2016-05-03',
    workUnit: '一局',
    department: '技术组',
    post: '技术员',
    grade: '组长'
  },
  {
    employmentDate: '2018-05-03',
    endOfOffice: '2016-05-03',
    workUnit: '一局',
    department: '技术组',
    post: '技术员',
    grade: '组长'
  },
  {
    employmentDate: '2018-05-03',
    endOfOffice: '2016-05-03',
    workUnit: '一局',
    department: '技术组',
    post: '技术员',
    grade: '组长'
  },
  {
    employmentDate: '2018-05-03',
    endOfOffice: '2016-05-03',
    workUnit: '一局',
    department: '技术组',
    post: '技术员',
    grade: '组长'
  }
]
</script>
<style>
.head {
  margin: 8px;
  color: #000;
  height: 50px;
  line-height: 50px;
  font-size: 16px;
  font-weight: 600;
  border-bottom: 1px solid #ebeef5;
}
</style>
