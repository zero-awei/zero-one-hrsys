<template>
  <div style="width: 100%">
    <div class="head">奖惩信息</div>
    <el-table
      :data="reandpuInfo"
      table-layout="auto"
      style="padding-left: 30px"
      :cell-style="{ textAlign: 'center' }"
      :header-cell-style="{ 'text-align': 'center', color: '#000' }"
    >
      <el-table-column type="selection" width="34px" />
      <el-table-column
        width="150px"
        prop="rewardsAndPunishmentsTime"
        label="奖惩时间"
        sortabled
      />
      <el-table-column width="150px" prop="name" label="名称" sortable />
      <el-table-column
        width="150px"
        prop="classification"
        label="奖惩分类"
        sortable
      />
      <el-table-column width="150px" prop="unit" label="授予单位" sortable />
      <el-table-column />
    </el-table>
  </div>
</template>

<script lang="ts" setup>
import { inject } from 'vue'
const userData: any = inject('userData')
let { reandpuInfo } = userData
interface User {
  rewardsAndPunishmentsTime: string
  name: string
  classification: string
  unit: string
}
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
