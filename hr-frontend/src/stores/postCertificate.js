import { defineStore } from 'pinia'

export const usePostCertificateStore = defineStore('postCertificate', {
  state: () => ({
    tableTitle: '岗位(技能)证书',
    tableOperations: [
      {
        name: '搜索'
      },
      {
        name: '新增'
      }
    ],
    xmlData: [
      { id: 1, name: '排序号', prop: 'id' },
      { id: 2, name: '岗位(技能)证书', prop: 'name' }
    ],
    tableData: null,
    addTitle: '岗位(技能)证书',
    dataitem: [
      {
        label: '排序号',
        name: 'id',
        type: Number
      },
      {
        label: '岗位(技能)证书',
        name: 'name',
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
