import Request from '@/apis/request'
import { defineStore } from 'pinia'
const baseUrl = import.meta.env.VITE_HR_C2_2
export const LeaveStaffStore = defineStore('leaveStaff', {
  state: () => ({
    title: '离职员工',
    options: [{ name: '搜索' }, { name: '导出' }, { name: '过滤' }],
    tableData: null,
    dataitem: null,
    xmlData: [
      { id: 1, name: '员工编号', prop: 'id' },
      { id: 2, name: '员工姓名', prop: 'name' },
      { id: 3, name: '组织', prop: 'organization' },
      { id: 4, name: '部门', prop: 'department' },
      { id: 5, name: '职级', prop: 'rank' },
      { id: 6, name: '手机号码', prop: 'phoneNumber' },
      { id: 7, name: '性别', prop: 'sex' },
      { id: 8, name: '通讯地址', prop: 'mail_address' },
      { id: 9, name: '家庭联系人', prop: 'family_contact' },
      { id: 10, name: '家庭联系人电话', prop: 'family_contact_number' }
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
        baseUrl + '/query-all-FormerEmployees',
        null
      )
      const rows = data.data.rows
      this.tableData = rows
      console.log(this.tableData)
    },
    initDataItem() {
      this.dataitem = [
        {
          label: '员工编号',
          name: 'id',
          type: Number
        },
        {
          label: '员工姓名',
          name: 'name',
          type: String
        },
        {
          label: '组织',
          name: 'organization',
          type: String
        },
        {
          label: '部门',
          name: 'department',
          type: String
        },
        {
          label: '职级',
          name: 'rank',
          type: String
        },
        {
          label: '手机号码',
          name: 'phoneNumber',
          type: String
        },
        {
          label: '性别',
          name: 'sex',
          type: String
        },
        {
          label: '通讯地址',
          name: 'address',
          type: String
        },
        {
          label: '家庭联系人',
          name: 'familyContact',
          type: String
        },
        {
          label: '家庭联系人电话',
          name: 'familyContactNumber',
          type: String
        }
      ]
    },
    addData(val) {
      this.tableData.push(val)
    }
  }
})
