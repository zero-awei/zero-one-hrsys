<template>
  <el-row>
    <el-col :span="24">
      <el-row :gutter="20">
        <el-col :span="8">
          <el-card>
            <echarts :options="pieChartOptions" />
          </el-card>
          <el-card>
            <echarts :options="funnelChartOption" />
          </el-card>
        </el-col>
        <el-col :span="8">
          <el-card>
            <echarts :options="lineChartOption" />
          </el-card>
          <el-card>
            <echarts :options="circularChartOptions" />
          </el-card>
        </el-col>
        <el-col :span="8">
          <el-card>
            <Qualification
              class="qua"
              :title="qualificationData.title"
              :data="qualificationData.tableData"
            ></Qualification>
          </el-card>
        </el-col>
      </el-row>
    </el-col>
  </el-row>
</template>

<script setup>
import Qualification from '@/components/CareerQualifications.vue'
import { reactive } from 'vue'

const pieChartOptions = reactive({
  //标题
  title: {
    text: '学历分布'
  },
  tooltip: {},
  //图例数据
  legend: {
    data: ['博士', '硕士', '本科', '大专', '中专及以下']
  },
  color: [
    '#3880ff',
    '#0cd1e8',
    '#7e57ff',
    '#10dc60',
    '#ffd31a',
    '#0bb8cc',
    '#ffce00'
  ],
  series: [
    {
      name: '学历分布',
      type: 'pie',
      data: [
        { value: 48, name: '博士' },
        { value: 12, name: '硕士' },
        { value: 28, name: '本科' },
        { value: 8, name: '大专' },
        { value: 4, name: '中专及以下' }
      ]
    }
  ]
})
const circularChartOptions = reactive({
  title: {
    text: '机关与项目人员'
  },
  legend: {
    left: 'center'
  },
  color: [
    '#3880ff',
    '#0cd1e8',
    '#7e57ff',
    '#10dc60',
    '#ffd31a',
    '#0bb8cc',
    '#ffce00'
  ],
  series: [
    {
      name: '机关与项目人员',
      type: 'pie',
      radius: ['40%', '70%'],
      label: {
        show: true
      },
      emphasis: {
        label: {
          show: true,
          fontSize: 40,
          fontWeight: 'bold'
        }
      },
      data: [
        { value: 13, name: '局机关' },
        { value: 24, name: '二级单位' },
        { value: 17, name: '地区机关' },
        { value: 55, name: '项目人员' }
      ]
    }
  ]
})
const lineChartOption = reactive({
  title: {
    text: '职称分布'
  },
  xAxis: {
    data: ['正高级', '高级', '中级', '初级']
  },
  color: [
    '#3880ff',
    '#0cd1e8',
    '#7e57ff',
    '#10dc60',
    '#ffd31a',
    '#0bb8cc',
    '#ffce00'
  ],
  yAxis: {},
  series: [
    {
      type: 'bar',
      data: [1, 18, 7, 0]
    }
  ]
})
const funnelChartOption = reactive({
  title: {
    text: '漏斗图'
  },
  tooltip: {
    trigger: 'item',
    formatter: '{a} <br/>{b} : {c}%'
  },
  legend: {
    data: ['流失率']
  },
  color: [
    '#3880ff',
    '#0cd1e8',
    '#7e57ff',
    '#10dc60',
    '#ffd31a',
    '#0bb8cc',
    '#ffce00'
  ],
  calculable: true,
  series: [
    {
      name: '流失率',
      type: 'funnel',
      left: '10%',
      top: 60,
      // 宽度，可以是像素，也可以是百分比
      width: '80%',
      // 总高度（包含标题和图例）
      height: '75%',
      // 排序方式（'ascending', 'descending'，默认不排序）
      sort: 'descending',
      label: {
        show: true,
        position: 'inside'
      },
      // 每一层数据的描述
      data: [
        { value: 80, name: '访问' },
        { value: 50, name: '咨询' },
        { value: 30, name: '订单' },
        { value: 10, name: '退货' }
      ]
    }
  ]
})

const qualificationData = reactive({
  title: '职业资格',
  tableData: [
    {
      name: '软件工程师',
      val: 30, // 宽度百分比
      color: 'skyblue' // 颜色
    },
    {
      name: 'java工程师',
      val: 20,
      color: 'pink'
    },
    {
      name: 'java工程师',
      val: 50,
      color: 'pink'
    },
    {
      name: 'java工程师',
      val: 100,
      color: 'pink'
    }
  ]
})
</script>

<style lang="scss" scoped>
.el-card {
  margin-bottom: 20px;
}
</style>
