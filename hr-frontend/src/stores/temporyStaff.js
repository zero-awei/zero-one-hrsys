import { defineStore } from 'pinia'

export const TemporaryStaffStore = defineStore('temporyStaff', {
  state: () => ({
    title: '挂职人员花名册',
    options: [{ name: '搜索' }, { name: '导出' }, { name: '过滤' }],
    tableData: null,
    dataitem: null,
    xmlData: [
      { id: 1, name: '员工编号', prop: 'id' },
      { id: 2, name: '员工姓名', prop: 'name' },
      { id: 3, name: '员工状态', prop: 'empStatus' },
      { id: 4, name: '挂职状态', prop: 'tempStatus' },
      { id: 5, name: '挂职组织', prop: 'tempOrg' },
      { id: 6, name: '挂职部门', prop: 'tempDept' },
      { id: 7, name: '挂职开始时间', prop: 'tempStartTime' },
      { id: 8, name: '挂职结束时间', prop: 'tempEndTime' }
    ],

    //分页器
    pageIndex: 1,
    pageSize: 100
  }),
  actions: {
    initTableData() {
      this.tableData = [
        {
          id: 10001,
          name: '彭三',
          tempStatus: 'qwq',
          empStatus: '挂职进',
          tempOrg: '上海小组',
          tempDept: '项目部',
          tempStartTime: '2019-4-17',
          tempEndTime: '2020-4-17'
        },
        {
          id: 10002,
          name: '彭四',
          empStatus: 'qwq',
          tempStatus: '挂职进',
          tempOrg: '海小组',
          tempDept: '项目部',
          tempStartTime: '2019-4-17',
          tempEndTime: '2020-4-17'
        }
      ]
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
          label: '员工状态',
          name: 'empStatus',
          type: String
        },
        {
          label: '挂职状态',
          name: 'tempStatus',
          type: String
        },
        {
          label: '挂职组织',
          name: 'tempOrg',
          type: String
        },
        {
          label: '挂职部门',
          name: 'tempDept',
          type: String
        },
        {
          label: '挂职开始时间',
          name: 'tempStartTime',
          type: String
        },
        {
          label: '挂职结束时间',
          name: 'tempEndTime',
          type: String
        }
      ]
    },
    addData(val) {
      this.tableData.push(val)
    }
  }
})
