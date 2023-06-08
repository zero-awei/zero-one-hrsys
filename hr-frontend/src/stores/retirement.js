import { defineStore } from 'pinia'

export const RetireStaffStore = defineStore('retirement', {
  state: () => ({
    title: '离(退)休人员',
    options: [{ name: '搜索' }, { name: '导出' }, { name: '过滤' }],
    tableData: null,
    dataitem: null,
    xmlData: [
      { id: 1, name: '员工编号', prop: 'id' },
      { id: 2, name: '员工姓名', prop: 'name' },
      { id: 3, name: '性别', prop: 'sex' },
      { id: 4, name: '年龄', prop: 'age' },
      { id: 5, name: '通讯地址', prop: 'address' },
      { id: 6, name: '退休地', prop: 'retirePlace' },
      { id: 7, name: '家庭联系人', prop: 'familyContact' },
      { id: 8, name: '家庭联系人电话', prop: 'familyContactNumber' },
      { id: 9, name: '组织', prop: 'organization' },
      { id: 10, name: '部门', prop: 'department' },
      { id: 11, name: '职级', prop: 'level' },
      { id: 12, name: '退休前职务', prop: 'preRetirePosition' },
      { id: 13, name: '退休前岗位', prop: 'preRetireJob' },
      { id: 14, name: '退休时间', prop: 'retireTime' },
      { id: 15, name: '实际退休时间', prop: 'realRetireTime' },
      { id: 16, name: '手机号码', prop: 'phoneNumber' },
      { id: 17, name: '审批的养老金额', prop: 'money' }
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
          id: 12345,
          name: '张三',
          sex: '男',
          age: 30,
          address: 'xx区xx路xx号xx室',
          retirePlace: 'xxx',
          familyContact: '李四',
          familyContactNumber: '1231456',
          organization: '集团总部',
          department: '财务资金部',
          level: 'E3',
          preRetirePosition: '党支部书记',
          preRetireJob: '干部管理',
          retireTime: '2020-04-30',
          realRetireTime: '2020-04-30',
          phoneNumber: '12345',
          money: 12345
        },
        {
          id: 12346,
          name: '三张',
          sex: '男',
          age: 30,
          address: 'xx区xx路xx号xx室',
          retirePlace: 'xxx',
          familyContact: '李四',
          familyContactNumber: '1231456',
          organization: '集团总部',
          department: '财务资金部',
          level: 'E3',
          preRetirePosition: '党支部书记',
          preRetireJob: '干部管理',
          retireTime: '2020-04-30',
          realRetireTime: '2020-04-30',
          phoneNumber: '12345',
          money: 12345
        },
        {
          id: 12347,
          name: '里斯',
          sex: '男',
          age: 30,
          address: 'xx区xx路xx号xx室',
          retirePlace: 'xxx',
          familyContact: '李四',
          familyContactNumber: '1231456',
          organization: '集团总部',
          department: '财务资金部',
          level: 'E3',
          preRetirePosition: '党支部书记',
          preRetireJob: '干部管理',
          retireTime: '2020-04-30',
          realRetireTime: '2020-04-30',
          phoneNumber: '12345',
          money: 12345
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
