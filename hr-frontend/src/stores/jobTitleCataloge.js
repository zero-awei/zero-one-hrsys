import { defineStore } from 'pinia'

export const useJobTitleCatalogeStore = defineStore('jobTitleCataloge', {
  state: () => ({
    tableTitle: '职称目录',
    tableOperations: [{ name: '新增' }],
    xmlData: [
      { id: 1, name: '排序号', prop: 'id' },
      { id: 2, name: '职称代码', prop: 'number' },
      { id: 3, name: '职称目录名称', prop: 'name' },
      { id: 4, name: '职称目录类型', prop: 'catalogeType' },
      { id: 5, name: '职称类型', prop: 'titleType' }
    ],
    tableData: null,
    addTitle: '职称目录',
    dataitem: [
      {
        label: '排序号',
        name: 'id',
        type: Number
      },
      {
        label: '职称代码',
        name: 'number',
        type: String
      },
      {
        label: '职称目录名称',
        name: 'name',
        type: String
      },
      {
        label: '职称目录类型',
        name: 'catalogeType',
        type: Array,
        options: [
          {
            id: 1,
            optionData: '统计人员'
          },
          {
            id: 2,
            optionData: '审计专业人员'
          }
        ]
      },
      {
        label: '职称类型',
        name: 'titleType',
        type: Array,
        options: [
          {
            id: 0,
            optionData: '无匹配数据'
          }
        ]
      }
    ],
    pageSizes: ['10', '20'],
    total: 1000
  }),
  actions: {
    initTableData() {
      this.tableData = [
        {
          id: 1,
          number: '11111',
          name: '统计员',
          catalogeType: '统计人员'
        },
        {
          id: 2,
          number: '222',
          name: '审计师',
          catalogeType: '审计专业人员'
        }
      ]
    },
    addData(val) {
      this.tableData.push(val)
    }
  }
})
