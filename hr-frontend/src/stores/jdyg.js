import { getJdygData } from '@/apis/roster-qianmeng/jdyginfo'
import { defineStore } from 'pinia'

export const RentStaffStore = defineStore('jdyg', {
  state: () => ({
    title: '借调人员花名册',
    options: [{ name: '搜索' }, { name: '导出' }, { name: '过滤' }],
    tableData: null,
    dataitem: null,
    xmlData: [
      { id: 1, name: '员工编号', prop: 'id' },
      { id: 2, name: '员工姓名', prop: 'name' },
      { id: 3, name: '原组织', prop: 'originalOrganization' },
      { id: 4, name: '原部门', prop: 'originalDepartment' },
      { id: 5, name: '原职务', prop: 'originalPosition' },
      { id: 6, name: '原岗位', prop: 'originalJob' },
      { id: 7, name: '新组织', prop: 'newOrganization' },
      { id: 8, name: '新部门', prop: 'newDepartment' },
      { id: 9, name: '新职务', prop: 'newPosition' },
      { id: 10, name: '新岗位', prop: 'newJob' },
      { id: 11, name: '借调状态', prop: 'rentState' },
      { id: 12, name: '借调开始时间', prop: 'rentStartTime' },
      { id: 13, name: '借调结束时间', prop: 'rentEndTime' }
    ],

    //分页器
    pageIndex: 1,
    pageSize: 100,
    total: 100
    // pageSizes:[]
  }),
  actions: {
    initTableData() {
      // getJdygData()
      this.tableData = [
        {
          id: 10001,
          name: '彭于晏',
          originalOrganization: '山东公司',
          originalDepartment: '人力资源部',
          originalPosition: '助理总经理',
          originalJob: '工会主席',
          newOrganization: 'xxx',
          newDepartment: '市场部',
          newPosition: '部门经理',
          newJob: '薪资专员',
          rentState: '借调中',
          rentStartTime: '2023-05-24',
          rentEndTime: '2023-05-26'
        },
        {
          id: 10002,
          name: '彭于',
          originalOrganization: '山东公司',
          originalDepartment: '人力资源部',
          originalPosition: '助理总经理',
          originalJob: '工会主席',
          newOrganization: 'xxx',
          newDepartment: '市场部',
          newPosition: '部门经理',
          newJob: '薪资专员',
          rentState: '借调中',
          rentStartTime: '2023-05-24',
          rentEndTime: '2023-05-26'
        },
        {
          id: 10004,
          name: '彭啥的',
          originalOrganization: '山东公司',
          originalDepartment: '人力资源部',
          originalPosition: '助理总经理',
          originalJob: '工会主席',
          newOrganization: 'xxx',
          newDepartment: '市场部',
          newPosition: '部门经理',
          newJob: '薪资专员',
          rentState: '借调中',
          rentStartTime: '2023-05-24',
          rentEndTime: '2023-05-26'
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
          label: '原组织',
          name: 'originalOrganization',
          type: String
        },
        {
          label: '原部门',
          name: 'originalDepartment',
          type: String
        },
        {
          label: '原职务',
          name: 'originalPosition',
          type: String
        },
        {
          label: '原岗位',
          name: 'originalJob',
          type: String
        },
        {
          label: '新组织',
          name: 'newOrganization',
          type: String
        },
        {
          label: '新部门',
          name: 'newDepartment',
          type: String
        },
        {
          label: '新职务',
          name: 'newPosition',
          type: String
        },
        {
          label: '新岗位',
          name: 'newJob',
          type: String
        },
        {
          label: '借调状态',
          name: 'rentState',
          type: String
        },
        {
          label: '借调开始时间',
          name: 'rentStartTime',
          type: String
        },
        {
          label: '借调结束时间',
          name: 'rentEndTime',
          type: String
        }
      ]
    },
    addData(val) {
      this.tableData.push(val)
    }
  }
})
