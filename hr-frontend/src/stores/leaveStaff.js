import { defineStore } from 'pinia'

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
      { id: 8, name: '通讯地址', prop: 'address' },
      { id: 9, name: '家庭联系人', prop: 'familyContact' },
      { id: 10, name: '家庭联系人电话', prop: 'familyContactNumber' }
    ],

    //分页器
    pageIndex: 1,
    pageSize: 100,
    total: 100
    // pageSizes:[]
  }),
  actions: {
    initTableData() {
      this.tableData = [
        {
          id: 10001,
          name: '彭于晏',
          organization: '集团总部',
          department: '企业部门',
          level: 'E3',
          phoneNumber: '123454',
          sex: '男',
          address: 'xxxx',
          familyContact: '张三',
          familyContactNumber: '123455'
        },
        {
          id: 10002,
          name: '彭于',
          organization: '集团总部',
          department: '企业部门',
          rank: 'E3',
          phoneNumber: '123454',
          sex: '男',
          address: 'xxxx',
          familyContact: '张三',
          familyContactNumber: '123455'
        },
        {
          id: 10004,
          name: '彭三',
          organization: '集团总部',
          department: '企业部门',
          rank: 'E3',
          phoneNumber: '123454',
          sex: '男',
          address: 'xxxx',
          familyContact: '张三',
          familyContactNumber: '123455'
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
