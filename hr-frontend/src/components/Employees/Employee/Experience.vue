<template>
  <div class="workRecord">
    <div class="head">工作履历</div>
    <el-table
      :data="userData.workRecord"
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
      <!-- <el-table-column width="150px" :prop="grade" label="职级" sortable /> -->
      <el-table-column />
    </el-table>
  </div>
</template>

<script lang="ts" setup>
//引入数据
import { inject } from 'vue'
const userData: any = inject('userData')

interface User {
  employmentDate: string
  endOfOffice: string
  workUnit: string
  department: string
  post: string
  grade: string
}
</script>
<style scoped>
.workRecord {
  padding: 12px 0 10px 16px;
  z-index: 0;
}
.head {
  padding: 0 10px 10px 10px;
  color: #000;
  height: 50px;
  line-height: 50px;
  font-size: 16px;
  font-weight: 600;
  border-bottom: 1px solid #d8dae0;
}
</style>
