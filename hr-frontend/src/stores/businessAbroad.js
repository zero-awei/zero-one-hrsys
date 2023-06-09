import { defineStore } from 'pinia'

export const useBusinessAbroadStore = defineStore('businessAbroad', {
  state: () => ({
    tableTitle: '因公出(国)境',
    tableOperations: [
      {
        name: '搜索'
      }
    ],
    xmlData: [
      { id: 1, name: '员工编号', prop: 'id' },
      { id: 2, name: '员工姓名', prop: 'name' },
      { id: 3, name: '员工状态', prop: 'state' },
      { id: 4, name: '组织', prop: 'organization' },
      { id: 5, name: '职级', prop: 'rank' },
      { id: 6, name: '目的国家/地区', prop: 'destination' },
      { id: 7, name: '出(国)境时间', prop: 'leaveTime' },
      { id: 8, name: '入(国)境时间', prop: 'backTime' },
      { id: 9, name: '类型', prop: 'Type' },
      { id: 10, name: '事由', prop: 'cause' },
      { id: 11, name: '流程状态', prop: 'processState' }
    ],
    tableData: null,
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
