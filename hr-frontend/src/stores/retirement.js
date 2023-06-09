import Request from '@/apis/request'
import { defineStore } from 'pinia'
export const RetireStaffStore = defineStore('retirement', {
  state: () => ({
    title: '离(退)休人员',
    options: [{ name: '搜索' }, { name: '导出' }, { name: '过滤' }],
    tableData: null,
    dataitem: null,
    baseUrl: import.meta.env.VITE_HR_C2_2,
    xmlData: [
      { id: 1, name: '员工编号', prop: 'ygbh' },
      { id: 2, name: '员工姓名', prop: 'pimpersonname' },
      { id: 3, name: '性别', prop: 'xb' },
      { id: 4, name: '年龄', prop: 'nj' },
      { id: 5, name: '通讯地址', prop: 'postaladdress' },
      { id: 6, name: '退休地', prop: 'retiPlace' },
      { id: 7, name: '家庭联系人', prop: 'jtlxr' },
      { id: 8, name: '家庭联系人电话', prop: 'jtlxrdh' },
      { id: 9, name: '组织', prop: 'zz' },
      { id: 10, name: '部门', prop: 'bm' },
      { id: 11, name: '职级', prop: 'rank' },
      { id: 12, name: '退休前职务', prop: 'yzw' },
      { id: 13, name: '退休前岗位', prop: 'ygw' },
      { id: 14, name: '退休时间', prop: 'txdq' },
      { id: 15, name: '实际退休时间', prop: 'sjtxrq' },
      { id: 16, name: '手机号码', prop: 'lxdh' },
      { id: 17, name: '审批的养老金额', prop: 'spdylje' }
    ],

    //分页器
    total: 1000
    // pageSizes:[]
  }),
  actions: {
    async initTableData(pageSize, pageIndex) {
      let data = await Request.requestForm(
        Request.GET,
        this.baseUrl + '/query-CheckRetiresList',
        {
          pageIndex: pageIndex,
          pageSize: pageSize
        },
        null
      )
      const rows = data.data.rows
      this.tableData = rows
      this.total = data.data.total
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
          label: '性别',
          name: 'sex',
          type: String
        },
        {
          label: '年龄',
          name: 'age',
          type: String
        },
        {
          label: '通讯地址',
          name: 'address',
          type: String
        },
        {
          label: '退休地',
          name: 'retirePlace',
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
          name: 'level',
          type: String
        },
        {
          label: '退休前职务',
          name: 'preRetirePosition',
          type: String
        },
        {
          label: '退休前岗位',
          name: 'preRetireJob',
          type: String
        },
        {
          label: '退休时间',
          name: 'retireTime',
          type: String
        },
        {
          label: '实际退休时间',
          name: 'realRetireTime',
          type: String
        },
        {
          label: '手机号码',
          name: 'phoneNumber',
          type: String
        },
        {
          label: '审批的养老金额',
          name: 'money',
          type: String
        }
      ]
    },
    addData(val) {
      this.tableData.push(val)
    }
  }
})
