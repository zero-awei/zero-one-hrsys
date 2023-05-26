<template>
  <div ref="chart"
       :style="{width: '100%', height: '400px'}"></div>
</template>

<script>
import * as echarts from 'echarts'

export default {
  props: {
    options: {
      type: Object,
      required: true
    },
    colorList: {
      type: Array,
      default: () => [
        '#c6e48b',
        '#7bc96f',
        '#239a3b',
        '#196127',
        '#ffd43b',
        '#ffc107',
        '#ff9800',
        '#e68a00',
        '#ff77aa',
        '#c0c0c0',
        '#7f7f7f',
        '#4d4d4d',
        '#5484ed',
        '#2ecc71',
        '#e74c3c',
        '#9b59b6',
        '#34495e',
        '#f1c40f',
        '#e67e22',
        '#95a5a6'
      ]
      ,
    },

  },
  mounted () {
    this.drawChart()
  },
  methods: {
    drawChart () {
      const chartDom = this.$refs.chart
      const myChart = echarts.init(chartDom)
      // 使用 props 传入的 colorList 数组配置颜色
      myChart.setOption({
        color: this.colorList,
      })
      myChart.setOption(this.options)


    }
  },
  watch: {
    options (newVal) {
      this.drawChart()
    }
  }
};
</script>
