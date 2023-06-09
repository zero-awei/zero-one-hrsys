import { defineStore } from 'pinia'
import Request from '@/apis/request'

export const useDispatchStore = defineStore('dispatch', {
  state: () => ({
    baseUrl: import.meta.env.VITE_HR_C6_1 + '/contract-management',
    tableTitle: '劳务派遣公司',
    tableOperations: [
      {
        name: '搜索'
      },
      {
        name: '新增'
      },
      {
        name: '删除'
      }
    ],
    xmlData: [
      { id: 1, name: '公司名称', prop: 'name' },
      { id: 2, name: '所属单位', prop: 'unit' },
      { id: 3, name: '联系地址', prop: 'lxdz' },
      { id: 4, name: '联系人', prop: 'lxr' },
      { id: 5, name: '联系电话', prop: 'lxfs' },
      { id: 6, name: '法人', prop: 'legalperson' },
      { id: 7, name: '注册资本', prop: 'regcapital' },
      { id: 8, name: '更新时间', prop: 'updatedate' }
    ],
    tableData: null,
    addTitle: '劳务派遣公司',
    dataitem: [
      {
        label: '公司名称',
        name: 'name',
        type: String
      },
      {
        label: '所属单位',
        name: 'unit',
        type: String
      },
      {
        label: '联系地址',
        name: 'lxdz',
        type: String
      },
      {
        label: '联系人',
        name: 'lxr',
        type: String
      },
      {
        label: '联系电话',
        name: 'lxfs',
        type: String
      },
      {
        label: '法人',
        name: 'legalperson',
        type: String
      },
      {
        label: '注册资本',
        name: 'regcapital',
        type: String
      },
      {
        label: '公司简介',
        name: 'gsjj',
        type: 'Text'
      }
    ],
    total:null
  }),
  actions: {
    async initTableData(pageSize,pageIndex) {
      let data = await Request.requestForm(
        Request.GET,
        this.baseUrl+'/queryPages-laborDispatch-Information',
        {
          "pageIndex": pageIndex,
          "pageSize": pageSize,
        },
        null
      )
      const rows = data.data.rows
      const totals=data.data.total
      this.total = totals
      this.tableData = rows
    },
    addData(val) {
      this.tableData.push(val)
    }
  }
})
