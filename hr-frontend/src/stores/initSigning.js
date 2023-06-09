import { defineStore } from 'pinia'
import Request from '@/apis/request'

export const useInitSigningStore = defineStore('initSigning', {
  state: () => ({
    baseUrl: import.meta.env.VITE_HR_C6_1 + '/contract-management',
    tableTitle: '初签(续签)提醒',
    tableOperations: [
      {
        name: '搜索'
      }
    ],
    xmlData: [
      { id: 1, name: '员工编号', prop: 'id' },
      { id: 2, name: '员工姓名', prop: 'name' },
      { id: 3, name: '员工所属单位', prop: 'Employee_unit' },
      { id: 4, name: '员工状态', prop: 'employee_state' },
      { id: 5, name: '到本单位时间', prop: 'Time_unit' },
      { id: 6, name: '合同编号', prop: 'contract_id' },
      { id: 7, name: '合同签订单位', prop: 'Contract_unit' },
      { id: 8, name: '合同类别', prop: 'Class_contract' },
      { id: 9, name: '合同类型', prop: 'contract_type' },
      { id: 10, name: '起始时间', prop: 'start_date' },
      { id: 11, name: '结束时间', prop: 'stop_date' },
      { id: 12, name: '操作列', prop: 'Operation_column' }
    ],
    tableData: null,
    total: null
  }),
  actions: {
    async initTableData(pageSize,pageIndex) {
      let data = await Request.requestForm(
        Request.GET,
        this.baseUrl+'/Page-query-Contract',
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
