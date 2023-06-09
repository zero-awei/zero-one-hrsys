import { defineStore } from 'pinia'

export const useTerminationStore = defineStore('termination', {
  state: () => ({
    tableTitle: '终止提醒',
    tableOperations: [
      {
        name: '搜索'
      }
    ],
    xmlData: [
      { id: 1, name: '员工编号', prop: 'id' },
      { id: 2, name: '员工姓名', prop: 'name' },
      { id: 3, name: '员工所属单位', prop: 'belong' },
      { id: 4, name: '员工状态', prop: 'state' },
      { id: 5, name: '到本单位时间', prop: 'entryTime' },
      { id: 6, name: '合同编号', prop: 'contractNo' },
      { id: 7, name: '合同签订单位', prop: 'signingUnit' },
      { id: 8, name: '合同类别', prop: 'contractCategory' },
      { id: 9, name: '合同类型', prop: 'contractType' },
      { id: 10, name: '起始时间', prop: 'startTime' },
      { id: 11, name: '结束时间', prop: 'endTime' },
      { id: 12, name: '操作列', prop: 'operation' }
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
