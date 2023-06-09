import Request from '@/apis/request'
import { defineStore } from 'pinia'
import { ref } from 'vue'

export const ProbationaryStaffStore = defineStore('syqyg', {
  state: () => ({
    title: '试用员工',
    options: [{ name: '搜索' }, { name: '导出' }],
    tableData: null,
    dataitem: null,
    baseUrl: import.meta.env.VITE_HR_C2_2,
    xmlData: [
      { id: 1, name: '员工编号', prop: 'id' },
      { id: 2, name: '员工姓名', prop: 'name' },
      { id: 3, name: '组织', prop: 'zz' },
      { id: 4, name: '部门', prop: 'bm' },
      { id: 5, name: '职务', prop: 'zw' },
      { id: 6, name: '岗位', prop: 'gw' },
      {
        id: 7,
        name: '到本单位时间',
        prop: 'rzsj'
      },
      {
        id: 8,
        name: '试用到期时间',
        prop: 'daoqishijian'
      }
    ],

    total: 1000
    // pageSizes:[]
  }),
  actions: {
    async initTableData(pageSize, pageIndex) {
      let data = await Request.requestForm(
        Request.GET,
        this.baseUrl + '/query-all-ProbationaryEmployee',
        {
          pageIndex: pageIndex,
          pageSize: pageSize
        },
        null
      )
      const rows = data.data.rows
      this.tableData = rows
      this.total = data.data.total
    }
  }
})
