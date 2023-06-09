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
      { id: 1, name: '排序', prop: 'px' },
      { id: 2, name: '组织名称', prop: 'orgname' },
      { id: 3, name: '组织简称', prop: 'shortname' },
      { id: 4, name: '组织编号', prop: 'orgcode' },
      { id: 5, name: '所属区域', prop: 'gsss' },
      { id: 6, name: '补贴标准', prop: 'btqy' },
      { id: 7, name: '组织启用时间', prop: 'zzcjsj' },
      { id: 8, name: '启停标识', prop: 'startstopsign' }
    ],
    tableData: null,
    pageSizes: ['10', '20'],
    total: 1000,
    addTitle: '组织信息',
    dataitem: [
      {
        label: '组织名称',
        name: 'orgname',
        type: String
      },
      {
        label: '组织编号',
        name: 'orgcode',
        type: String
      },
      {
        label: '组织简称',
        name: 'shortname',
        type: String
      },
      {
        label: '排序',
        name: 'px',
        type: String
      },
      {
        label: '所属区域',
        name: 'gsss',
        type: String
      },
      {
        label: '补贴标准',
        name: 'btqy',
        type: String
      },
      {
        label: '组织启用时间',
        name: 'zzcjsj',
        type: String
      },
      {
        label: '启停标识',
        name: 'startstopsign',
        type: String
      },
      {
        label: '组织ID',
        name: 'orgid',
        type: String
      },
      {
        label: '上级组织ID',
        name: 'porgid',
        type: String
      }
    ]
  }),
  actions: {
    initTableData() {
      this.tableData = [
        {
          px: 1,
          orgname: '薇欧拉',
          shortname: '薇欧拉',
          orgcode: '1000',
          gsss: '其他',
          btqy: 'A类地区',
          zzcjsj: '2023-05-02',
          startstopsign: '启用'
        },
        {
          px: 1,
          orgname: '上海分公司',
          shortName: '上海分公司',
          orgcode: '000001',
          gsss: '华东地区',
          btqy: 'A类地区',
          zzcjsj: '2023-01-02',
          startstopsign: '启用'
        }
      ]
    },
    addData(val) {
      this.tableData.push(val)
    }
  }
})
