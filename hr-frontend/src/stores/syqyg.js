import Request from '@/apis/request'
import { defineStore } from 'pinia'
import { ref } from 'vue'
const baseUrl = import.meta.env.VITE_HR_C2_2
export const ProbationaryStaffStore = defineStore('syqyg', {
  state: () => ({
    title: '试用员工',
    options: [{ name: '搜索' }, { name: '导出' }],
    tableData: null,
    dataitem: null,
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

    //分页器
    pageIndex: 1,
    pageSize: 100,
    total: ref(100)
    // pageSizes:[]
  }),
  actions: {
    async initTableData() {
      let data = await Request.requestForm(
        Request.GET,
        baseUrl + '/query-all-ProbationaryEmployee',
        null
      )
      const rows = data.data.rows
      this.tableData = rows
    }
    // initDataItem() {
    //   this.dataitem = [
    //     {
    //       label: '员工编号',
    //       name: 'id',
    //       type: Number
    //     },
    //     {
    //       label: '员工姓名',
    //       name: 'name',
    //       type: String
    //     },
    //     {
    //       label: '组织',
    //       name: 'zz',
    //       type: String
    //     },
    //     {
    //       label: '部门',
    //       name: 'bm',
    //       type: String
    //     },
    //     {
    //       label: '职务',
    //       name: 'zw',
    //       type: String
    //     },
    //     {
    //       label: '岗位',
    //       name: 'gw',
    //       type: String
    //     },
    //     {
    //       label: '到本单位时间',
    //       name: 'rzsj',
    //       type: String
    //     },
    //     {
    //       label: '试用到期时间',
    //       name: 'daoqishijian',
    //       type: String
    //     }
    //   ]
    // },
    // addData(val) {
    //   this.tableData.push(val)
    // }
  }
})
