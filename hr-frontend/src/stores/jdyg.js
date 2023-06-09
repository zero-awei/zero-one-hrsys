import Request from '@/apis/request'
import { defineStore } from 'pinia'
const baseUrl = import.meta.env.VITE_HR_C2_2
export const RentStaffStore = defineStore('jdyg', {
  state: () => ({
    title: '借调人员花名册',
    options: [{ name: '搜索' }, { name: '导出' }, { name: '过滤' }],
    tableData: null,
    dataitem: null,
    xmlData: [
      { id: 1, name: '员工编号', prop: 'ygbh' },
      { id: 2, name: '员工姓名', prop: 'pimPersonName' },
      { id: 3, name: '原组织', prop: 'zz' },
      { id: 4, name: '原部门', prop: 'bm' },
      { id: 5, name: '原职务', prop: 'yzw' },
      { id: 6, name: '原岗位', prop: 'ygw' },
      { id: 7, name: '新组织', prop: 'ormName' },
      { id: 8, name: '新部门', prop: 'ormOrgSectorName' },
      { id: 9, name: '新职务', prop: 'ormDutyName' },
      { id: 10, name: '新岗位', prop: 'ormPostName' },
      { id: 11, name: '借调状态', prop: 'pcmydjdmxId' },
      { id: 12, name: '借调开始时间', prop: 'jdksrq' },
      { id: 13, name: '借调结束时间', prop: 'jdjsrq' }
    ],

    //分页器
    pageIndex: 1,
    pageSize: 100,
    total: 100
    // pageSizes:[]
  }),
  actions: {
    async initTableData() {
      let data = await Request.requestForm(
        Request.GET,
        baseUrl + '/query-LoanedPerPage',
        null
      )
      const rows = data.data.rows
      this.tableData = rows
    },
    initDataItem() {
      this.dataitem = [
        {
          label: '员工编号',
          name: 'ygbh',
          type: Number
        },
        {
          label: '员工姓名',
          name: 'pimPersonName',
          type: String
        },
        {
          label: '原组织',
          name: 'zz',
          type: String
        },
        {
          label: '原部门',
          name: 'bm',
          type: String
        },
        {
          label: '原职务',
          name: 'yzw',
          type: String
        },
        {
          label: '原岗位',
          name: 'ygw',
          type: String
        },
        {
          label: '新组织',
          name: 'ormName',
          type: String
        },
        {
          label: '新部门',
          name: 'ormOrgSectorName',
          type: String
        },
        {
          label: '新职务',
          name: 'ormDutyName',
          type: String
        },
        {
          label: '新岗位',
          name: 'ormPostName',
          type: String
        },
        {
          label: '借调状态',
          name: 'pcmydjdmxId',
          type: String
        },
        {
          label: '借调开始时间',
          name: 'jdksrq',
          type: String
        },
        {
          label: '借调结束时间',
          name: 'jdjsrq',
          type: String
        }
      ]
    },
    addData(val) {
      this.tableData.push(val)
    }
  }
})
