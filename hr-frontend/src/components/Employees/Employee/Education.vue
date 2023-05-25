<template>
  <div class="educationInfo">
    <div class="head">教育背景</div>
    <el-table
      :data="educationInfo"
      table-layout="auto"
      style="padding-left: 30px"
      :cell-style="{ textAlign: 'center' }"
      :header-cell-style="{ 'text-align': 'center', color: '#000' }"
    >
      <el-table-column type="selection" width="34px" />
      <el-table-column width="150px" prop="degree" label="学历" sortable />
      <el-table-column
        width="150px"
        prop="admission"
        label="入学时间"
        sortable
      />
      <el-table-column
        width="150px"
        prop="graduation"
        label="毕业时间"
        sortable
      />
      <el-table-column width="150px" prop="school" label="毕业院校" sortable />
      <el-table-column
        width="150px"
        prop="firstDiscipline"
        label="一级学科"
        sortable
      />
      <el-table-column width="150px" prop="major" label="所学专业" sortable />
      <el-table-column
        width="180px"
        prop="studyMode"
        label="学习形式"
        sortable
      />
      <el-table-column
        width="150px"
        prop="category"
        label="学校性质"
        sortable
      />
      <el-table-column
        width="150px"
        prop="ifFirstDegree"
        label="是否第一学历"
        sortable
      />
      <el-table-column
        width="150px"
        prop="ifHighestDegree"
        label="是否最高学历"
        sortable
      />
      <el-table-column />
    </el-table>
  </div>
</template>

<script lang="ts" setup>
interface User {
  degree: string
  date: string
  admission: string
  graduation: string
  school: string
  firstDiscipline: string
  major: string
  studyMode: string
  category: string
  ifFirstDegree: string
  ifHighestDegree: string
}

import { inject } from 'vue'
const userData: any = inject('userData')
let { educationInfo } = userData
</script>
<style scoped>
.educationInfo {
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
