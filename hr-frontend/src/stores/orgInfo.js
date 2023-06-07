import { defineStore } from 'pinia'

export const orgInfoStore = defineStore('orginfo', {
  state: () => ({
    tableTitle: '组织信息',
    tableOperations: [
      {
        name: '新增'
      },
      {
        name: '过滤'
      }
    ],
    menus: [
      {
        path: '/sample',
        text: '空白页',
        icon: 'user'
      },
      {
        path: '/sample/excel',
        text: 'Excel演示',
        icon: 'user'
      },
      {
        path: '/sample/print',
        text: '打印演示',
        icon: 'user'
      },
      {
        path: '/sample/edit',
        text: '信息编辑页',
        icon: 'user'
      },
      {
        path: '/sample/sass',
        text: 'sass演示',
        icon: 'user'
      },
      {
        path: '/sample/communication',
        text: '兄弟组件通信',
        icon: 'user'
      },
      {
        path: '/sample/pagination',
        text: '分页',
        icon: 'user'
      },
      {
        path: '/sample/sass',
        text: 'sass演示',
        icon: 'user'
      },
      {
        path: '/sample/communication',
        text: '兄弟组件通信',
        icon: 'user'
      },
      {
        path: '/sample/pagination',
        text: '分页',
        icon: 'user'
      },
      {
        path: '/sample/sass',
        text: 'sass演示',
        icon: 'user'
      },
      {
        path: '/sample/communication',
        text: '兄弟组件通信',
        icon: 'user'
      },
      {
        path: '/sample/pagination',
        text: '分页',
        icon: 'user'
      },
      {
        path: '/sample/sass',
        text: 'sass演示',
        icon: 'user'
      },
      {
        path: '/sample/communication',
        text: '兄弟组件通信',
        icon: 'user'
      },
      {
        path: '/sample/pagination',
        text: '分页',
        icon: 'user'
      }
    ],
    xmlData: [
      { id: 1, name: '排序', prop: 'ouId' },
      { id: 2, name: '组织名称', prop: 'orgInfoName' },
      { id: 3, name: '组织简称', prop: 'shortName' },
      { id: 4, name: '组织编号', prop: 'orgCode' },
      { id: 5, name: '所属区域', prop: 'belongRegion' },
      { id: 6, name: '补贴标准', prop: 'subStandard' },
      { id: 7, name: '组织启用时间', prop: 'createDate' },
      { id: 8, name: '启停标识', prop: 'startStopSign' }
    ],
    tableData: null,
    pageSizes: ['10', '20'],
    total: 1000,
    addTitle: '组织信息',
    dataitem: [
      {
        label: '组织名称',
        name: 'orgInfoName',
        type: String
      },
      {
        label: '组织编号',
        name: 'orgCode',
        type: String
      },
      {
        label: '组织简称',
        name: 'shortName',
        type: String
      },
      {
        label: '排序',
        name: 'ouId',
        type: Number
      },
      {
        label: '所属区域',
        name: 'belongRegion',
        type: String
      },
      {
        label: '补贴标准',
        name: 'subStandard',
        type: String
      },
      {
        label: '组织启用时间',
        name: 'createDate',
        type: String
      },
      {
        label: '启停标识',
        name: 'startStopSign',
        type: String
      }
    ]
  }),
  actions: {
    initTableData() {
      this.tableData = [
        {
          ouId: 1,
          orgInfoName: '薇欧拉',
          shortName: '薇欧拉',
          orgCode: '1000',
          belongRegion: '其他',
          subStandard: 'A类地区',
          createDate: '2023-05-02',
          startStopSign: '启用'
        },
        {
          ouId: 1,
          orgInfoName: '上海分公司',
          shortName: '上海分公司',
          orgCode: '000001',
          belongRegion: '华东地区',
          subStandard: 'A类地区',
          createDate: '2023-01-02',
          startStopSign: '启用'
        }
      ]
    },
    addData(val) {
      this.tableData.push(val)
    }
  }
})
