import { defineStore } from 'pinia'
import Request from '@/apis/request'
const baseUrl = import.meta.env.VITE_HR_J2_2

export const portalStore = defineStore('portal', {
  state: () => ({
    pieChart: null,
    funnelChart: null,
    lineChart: null,
    circularChart: null,
    qualification: null
  }),
  actions: {
    // 获取表单数据
    async initPieChart() {
      let { data } = await Request.request(
        Request.GET,
        baseUrl + '/query-education-distribution',
        null
      )
      const legendName = data.map((item) => item.educationname)
      this.pieChart = {
        //标题
        title: {
          text: '学历分布'
        },
        tooltip: {},
        //图例数据
        legend: {
          data: legendName
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
            data: data
          }
        ]
      }
    },
    async initFunnelChart() {
      let { data } = await Request.request(
        Request.GET,
        baseUrl + '/query-age-distribution',
        null
      )
      this.funnelChart = {
        title: {
          text: '年龄分布'
        },
        tooltip: {
          trigger: 'item',
          formatter: '{a} <br/>{b} : {c}%'
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
            data: data
          }
        ]
      }
    },
    initLineChart() {
      //let data = await Request.request(Request.GET, '/portal', null)
      //this.pieChart = data.data
      this.lineChart = {
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
      }
    },
    initCircularChart() {
      // let data = await Request.request(Request.GET, '/portal', null)
      //this.pieChart = data.data
      this.circularChart = {
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
      }
    },
    async initQualification() {
      try {
        let { data } = await Request.request(
          Request.GET,
          baseUrl + '/query-vocational',
          null
        )
        let color = ['#3880ff', '#0cd1e8', '#7e57ff', '#10dc60', '#ffd31a']
        data.map((item, index) => {
          item.color = color[index]
        })
        this.qualification = {
          title: '职业资格',
          tableData: data
        }
      } catch (error) {
        return error
      }
    }
  }
})
