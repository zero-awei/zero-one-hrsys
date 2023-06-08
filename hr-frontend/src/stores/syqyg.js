import { defineStore } from 'pinia'

export const ProbationaryStaffStore = defineStore('syqyg', {
  state: () => ({
    title: '试用员工',
    options: [{ name: '搜索' }, { name: '导出' }],
    tableData: null,
    dataitem: null,
    xmlData: [
      { id: 1, name: '员工编号', prop: 'id' },
      { id: 2, name: '员工姓名', prop: 'name' },
      { id: 3, name: '组织', prop: 'organization' },
      { id: 4, name: '部门', prop: 'department' },
      { id: 5, name: '职务', prop: 'position' },
      { id: 6, name: '岗位', prop: 'job' },
      {
        id: 7,
        name: '到本单位时间',
        prop: 'comeTime'
      },
      {
        id: 8,
        name: '试用到期时间',
        prop: 'expirTime'
      }
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
          position: '总规划师',
          job: '培训管理',
          comeTime: '2019-03-05',
          expirTime: '2023-06-01'
        },
        {
          id: 10002,
          name: '彭于',
          organization: '集团分部',
          department: '企业部门',
          position: '总规划师',
          job: '培训管理',
          comeTime: '2019-03-05',
          expirTime: '2022-06-01'
        },
        {
          id: 10003,
          name: '龚宇',
          organization: '集团总部',
          department: '企业部门',
          position: '规划师',
          job: '培训管理',
          comeTime: '2012-03-05',
          expirTime: '2013-06-01'
        },
        {
          id: 10004,
          name: '彭的晏',
          organization: '集团总部',
          department: '企业部门',
          position: '总规划师',
          job: '培训管理',
          comeTime: '2019-03-05',
          expirTime: '2023-06-01'
        },
        {
          id: 10005,
          name: '彭于让',
          organization: '集团总部',
          department: '企业部门',
          position: '总规划师',
          job: '培训管理',
          comeTime: '2019-03-05',
          expirTime: '2023-06-01'
        },
        {
          id: 10006,
          name: '彭发的',
          organization: '集团总部',
          department: '企业部门',
          position: '总规划师',
          job: '培训管理',
          comeTime: '2019-03-05',
          expirTime: '2023-06-01'
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
          label: '职务',
          name: 'position',
          type: String
        },
        {
          label: '岗位',
          name: 'job',
          type: String
        }
      ]
    },
    addData(val) {
      this.tableData.push(val)
    }
  }
})
