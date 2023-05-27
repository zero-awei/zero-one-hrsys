<!-- ECharts.vue -->
<template>
  <div :style="{ height: chartHeight }"
       ref="chart"></div>
</template>

<script>
import echarts from 'echarts'

export default {
  name: 'ECharts',
  props: {
    options: {
      type: Object,
      required: true,
    },
    chartHeight: {
      type: String,
      default: '400px',
    },
    colorList: {
      type: Array,
      default: () => ['#c23531', '#2f4554', '#61a0a8', '#d48265', '#91c7ae'],
    },
  },
  data () {
    return {
      chart: null,
    }
  },
  mounted () {
    this.initChart()
  },
  methods: {
    initChart () {
      this.chart = echarts.init(this.$refs.chart)

      // 使用 props 传入的 options 配置对象
      this.chart.setOption(this.options)

      // 使用 props 传入的 colorList 数组配置颜色
      this.chart.setOption({
        color: this.colorList,
      })
    },
  },
  created () {
    // 在 created 钩子函数中设置默认的颜色列表
    echarts.registerTheme('vibrant', {
      color: ['#5ab1ef', '#ffb980', '#a0d468', '#fbd57d', '#d87a80', '#8d98b3', '#e5cf0d', '#97b552', '#95706d', '#dc69aa', '#07a2a4', '#9a7fd1', '#588dd5'],
    })
    echarts.registerTheme('positive', {
      color: ['#2ec7c9', '#d87a80', '#919e8b', '#d7ab82', '#6e7074', '#61a0a8', '#efa18d', '#787464', '#cc7e63', '#724e58', '#4b565b'],
    })

    if (!this.colorList) {
      this.colorList = echarts.getTheme('vibrant').color
    }
  },
};
</script>
