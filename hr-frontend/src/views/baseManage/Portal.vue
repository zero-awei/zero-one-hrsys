<template>
  <el-row style="margin: 20px 10px">
    <el-col :span="24">
      <el-row :gutter="20" style="margin: 0">
        <el-col :span="8">
          <el-card>
            <echarts :options="$store.pieChart" />
          </el-card>
          <el-card>
            <echarts :options="$store.funnelChart" />
          </el-card>
        </el-col>
        <el-col :span="8">
          <el-card>
            <echarts :options="$store.lineChart" />
          </el-card>
          <el-card>
            <echarts :options="$store.circularChart" />
          </el-card>
        </el-col>
        <el-col :span="8">
          <el-card>
            <Qualification
              class="qua"
              :data="$store.qualification"
            ></Qualification>
          </el-card>
        </el-col>
      </el-row>
    </el-col>
  </el-row>
</template>

<script setup>
import Qualification from '@/components/CareerQualifications.vue'
import { portalStore } from '@/stores/portal'
const $store = portalStore()
// 测试写法
onBeforeMount(() => {
  $store.initPieChart()
  $store.initFunnelChart()
  $store.initLineChart()
  $store.initCircularChart()
  $store.initQualification()
})
</script>

<style lang="scss" scoped>
.el-card {
  margin-bottom: 20px;
}
</style>
