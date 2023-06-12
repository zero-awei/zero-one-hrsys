import { defineStore } from 'pinia'
import Request from '@/apis/request'

export const useTerminationStore = defineStore('termination', {
  state: () => ({
    baseUrl: import.meta.env.VITE_HR_C6_1 + '/contract-management',
    tableTitle: '终止提醒',
    tableOperations: [
      {
        name: '搜索'
      }
    ],
    xmlData: [
      { id: 1, name: '员工编号', prop: 'employee_id' },
      { id: 2, name: '员工姓名', prop: 'employee_name' },
      { id: 3, name: '员工所属单位', prop: 'employee_part' },
      { id: 4, name: '员工状态', prop: 'employee_status' },
      { id: 5, name: '到本单位时间', prop: 'arrived_time' },
      { id: 6, name: '合同编号', prop: 'contract_id' },
      { id: 7, name: '合同签订单位', prop: 'contract_sign_part' },
      { id: 8, name: '合同类别', prop: 'contract_lb' },
      { id: 9, name: '合同类型', prop: 'contract_lx' },
      { id: 10, name: '起始时间', prop: 'begin_time' },
      { id: 11, name: '结束时间', prop: 'deadline' },
    ],
    tableData: null,
    total: null
  }),
  actions: {
    async initTableData(pageSize,pageIndex) {
      let data = await Request.requestForm(
        Request.GET,
        this.baseUrl+'/reminder-query-contract',
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
