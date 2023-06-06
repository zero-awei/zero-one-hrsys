import { defineStore } from 'pinia'

export const useJobTitleInfoStore = defineStore('jobTitleInfo', {
  state: () => ({
    tableTitle: '职称信息',
    tableOperations: [
      {
        name: '搜索'
      }
    ],
    xmlData: [
      { id: 1, name: '员工编号', prop: 'id' },
      { id: 2, name: '员工姓名', prop: 'name' },
      { id: 3, name: '员工状态', prop: 'state' },
      { id: 4, name: '组织', prop: 'organization' },
      { id: 5, name: '职称名称', prop: 'jobTitle' },
      { id: 6, name: '获取日期', prop: 'getDate' },
      { id: 7, name: '证书编号', prop: 'certificateNo' },
      { id: 8, name: '专业类别', prop: 'professionalCategory' },
      { id: 9, name: '职称等级', prop: 'grade' },
      { id: 10, name: '职称获取月数', prop: 'gettingMonth' },
      { id: 11, name: '职称聘用时间', prop: 'employmentDate' },
      { id: 12, name: '签发机构', prop: 'issueAuthority' },
      { id: 13, name: '评审单位', prop: 'evaluationUnit' },
      { id: 14, name: '是否最高职称', prop: 'isTop' }
    ],
    tableData: null,
    pageSizes: ['10', '20'],
    total: 1000
  }),
  actions: {
    initTableData() {
      this.tableData = [
        {
          id: 1,
          name: '施工员'
        },
        {
          id: 2,
          name: '安全员'
        }
      ]
    },
    addData(val) {
      this.tableData.push(val)
    }
  }
})
