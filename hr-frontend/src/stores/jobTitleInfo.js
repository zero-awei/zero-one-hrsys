import { defineStore } from 'pinia'
import Request from '@/apis/request'

export const useJobTitleInfoStore = defineStore('jobTitleInfo', {
  state: () => ({
    baseUrl: import.meta.env.VITE_HR_C6_1 + '/job-title-management',
    tableTitle: '职称信息',
    tableOperations: [
      {
        name: '搜索'
      },
      {
        name:'新增'
      },
      {
        name:'删除'
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
    addTitle: '职称信息',
    dataitem:[
      {
        label: '员工编号',
        name: 'employee_id',
        type: String
      },
      {
        label: '员工姓名',
        name: 'employee_name',
        type: String
      },
      {
        label: '职称名称',
        name: 'jobtitle_name',
        type: String
      },
      {
        label: '获取日期',
        name: 'get_time',
        type: String
      },
      {
        label: '证书编号',
        name: 'certificate_id',
        type: String
      },
      {
        label: '职称等级',
        name: 'jobtitle_grades',
        type: String
      },
      {
        label: '专业类别',
        name: 'professional_cate',
        type: String
      },
      {
        label: '专业名称',
        name: 'professional_name',
        type: String
      },
      {
        label: '签发机构',
        name: 'issuing_authority',
        type: String
      },
      {
        label: '评审单位',
        name: 'judging_unit',
        type: String
      },
      {
        label: '职称聘用时间',
        name: 'title_employment_time',
        type: String
      },
      {
        label: '是否最高职称',
        name: 'b_highest_professional_title',
        type: String
      },
      {
        label: '上传附件',
        name: 'attachment',
        type: String
      }
    ],
    total: null
  }),
  actions: {
    async initTableData(pageSize,pageIndex) {
      let data = await Request.requestForm(
        Request.GET,
        this.baseUrl+'/query-jobtitle',
        {
          "pageIndex": pageIndex,
          "pageSize": pageSize,
        },
        null
      )
      const rows = data.data.rows
      const totals=data.data.total
      this.total = totals
      this.tableData = rows
    },
    addData(val) {
      this.tableData.push(val)
    }
  }
})
