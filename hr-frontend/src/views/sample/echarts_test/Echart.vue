<template>
  <el-row>
    <el-col :span="18">
      <el-row>
        <el-col :span="12">
          <echarts :options="pieChartOptions" />
          <echarts :options="funnelChartOption" />
        </el-col>
        <el-col :span="12">
          <echarts :options="lineChartOption" />
          <echarts :options="circularChartOptions" />
        </el-col>
      </el-row>
    </el-col>
  </el-row>
</template>

<script>
export default {
  data() {
    return {
      pieChartOptions: {
        title: {
          text: '学历分布'
        },
        tooltip: {},
        legend: {
          data: ['博士', '硕士', '本科', '大专', '中专及以下']
        },
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
      },
      circularChartOptions: {
        title: {
          text: '机关与项目人员'
        },
        series: [
          {
            type: 'pie',
            data: [
              {
                value: 13,
                name: '地区机关'
              },
              {
                value: 10,
                name: '二级单位'
              },
              {
                value: 1,
                name: '局机关'
              },
              {
                value: 1,
                name: '项目人员'
              }
            ],
            radius: ['40%', '70%']
          }
        ]
      },
      lineChartOption: {
        title: {
          text: '职称分布'
        },
        xAxis: {
          data: ['正高级', '高级', '中级', '初级']
        },
        yAxis: {},
        series: [
          {
            type: 'bar',
            data: [1, 18, 7, 0]
          }
        ]
      },
      funnelChartOption: {
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
      }
    }
  }
}
</script>

<style lang="scss">
.el-row {
  margin-bottom: 20px;
}
.el-row:last-child {
  margin-bottom: 0;
}
.el-col {
  border-radius: 4px;
}

.grid-content {
  border-radius: 4px;
  min-height: 36px;
}
</style>
