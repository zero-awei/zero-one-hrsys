import { defineStore } from 'pinia'

export const useDispatchStore = defineStore('dispatch', {
  state: () => ({
    tableTitle: '劳务派遣公司',
    tableOperations: [
      {
        name: '搜索'
      },
      {
        name: '新增'
      }
    ],
    xmlData: [
      { id: 1, name: '公司名称', prop: 'name' },
      { id: 2, name: '所属单位', prop: 'belong' },
      { id: 3, name: '联系地址', prop: 'address' },
      { id: 4, name: '联系人', prop: 'lxr' },
      { id: 5, name: '联系电话', prop: 'phone' },
      { id: 6, name: '注册资本', prop: 'zczb' },
      { id: 7, name: '法人', prop: 'legalman' },
      { id: 8, name: '更新时间', prop: 'updatetime' }
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
        name: 'belong',
        type: String
      },
      {
        label: '联系地址',
        name: 'address',
        type: String
      },
      {
        label: '联系人',
        name: 'lxr',
        type: String
      },
      {
        label: '联系电话',
        name: 'phone',
        type: String
      },
      {
        label: '注册资本',
        name: 'zczb',
        type: String
      },
      {
        label: '法人',
        name: 'legalman',
        type: String
      },
      {
        label: '更新时间',
        name: 'updatetime',
        type: String
      }
    ],
    pageSizes: ['10', '20'],
    total: 1000
  }),
  actions: {
    initTableData() {
      this.tableData = [
        {
          id: 1,
          name: '施工员'
        },
        {
          id: 2,
          name: '安全员'
        }
      ]
    },
    addData(val) {
      this.tableData.push(val)
    }
  }
})
