import { defineStore } from 'pinia'

export const useJobTitleInfoStore = defineStore('jobTitleInfo', {
  state: () => ({
    tableTitle: '职称信息',
    tableOperations: [
      {
        name: '搜索'
      },
      {
        name:'新增'
      }
    ],
    xmlData: [
      { id: 1, name: '员工编号', prop: 'employee_id' },
      { id: 2, name: '员工姓名', prop: 'employee_name' },
      { id: 3, name: '员工状态', prop: 'employee_state' },
      { id: 4, name: '组织', prop: 'org_name' },
      { id: 5, name: '职称名称', prop: 'jobtitle_name' },
      { id: 6, name: '获取日期', prop: 'get_time' },
      { id: 7, name: '证书编号', prop: 'certificate_id' },
      { id: 8, name: '专业类别', prop: 'professional_cate' },
      { id: 9, name: '职称等级', prop: 'jobtitle_grades' },
      { id: 10, name: '职称获取月数', prop: 'employment_month' },
      { id: 11, name: '职称聘用时间', prop: 'title_employment_time' },
      { id: 12, name: '签发机构', prop: 'issuing_authority' },
      { id: 13, name: '评审单位', prop: 'judging_unit' },
      { id: 14, name: '是否最高职称', prop: 'b_highest_professional_title' }
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
