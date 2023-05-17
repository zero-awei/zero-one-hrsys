<template>
  <div style="width: 100%">
    <div class="head">教育背景</div>
    <el-table
      :data="tableData"
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

const tableData: User[] = [
  {
    degree: '博士',
    date: '2016-05-03',
    admission: '2018-05-03',
    graduation: '2021-05-03',
    school: '北京大学',
    firstDiscipline: '土木工程',
    major: '土木工程',
    studyMode: '正规高等院校（统招）',
    category: '公办院校',
    ifFirstDegree: '是',
    ifHighestDegree: '是'
  },
  {
    degree: '博士',
    date: '2016-05-03',
    admission: '2018-05-03',
    graduation: '2021-05-03',
    school: '北京大学',
    firstDiscipline: '土木工程',
    major: '土木工程',
    studyMode: '正规高等院校（统招）',
    category: '公办院校',
    ifFirstDegree: '是',
    ifHighestDegree: '是'
  },
  {
    degree: '博士',
    date: '2016-05-03',
    admission: '2018-05-03',
    graduation: '2021-05-03',
    school: '北京大学',
    firstDiscipline: '土木工程',
    major: '土木工程',
    studyMode: '正规高等院校（统招）',
    category: '公办院校',
    ifFirstDegree: '是',
    ifHighestDegree: '是'
  },
  {
    degree: '博士',
    date: '2016-05-03',
    admission: '2018-05-03',
    graduation: '2021-05-03',
    school: '北京大学',
    firstDiscipline: '土木工程',
    major: '土木工程',
    studyMode: '正规高等院校（统招）',
    category: '公办院校',
    ifFirstDegree: '是',
    ifHighestDegree: '是'
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
