import { defineStore } from 'pinia'

export const useArchivesStore = defineStore('archives', {
  state: () => ({
    tableTitle: '档案室管理',
    tableOperations: [{ name: '新增' }],
    xmlData: [
      { id: 1, name: '排序号', prop: 'id' },
      { id: 2, name: '档案室名称', prop: 'name' },
      { id: 3, name: '柜号', prop: 'cabinet' },
      { id: 4, name: '层号', prop: 'floor' },
      { id: 5, name: '编号', prop: 'number' }
    ],
    tableData: null,
    addTitle: '档案室管理',
    dataitem: [
      {
        label: '排序号',
        name: 'id',
        type: Number,
      },

      {
        label: '档案室名称',
        name: 'name',
        type: String,
      },
      {
        label: '柜号',
        name: 'cabinet',
        type: String,
      },
      {
        label: '层号',
        name: 'floor',
        type: Array,
        options: [
          {
            id: 1,
            optionData: '上'
          },
          {
            id: 2,
            optionData: '中'
          },
          {
            id: 3,
            optionData: '下'
          }
        ]
      },
      {
        label: '编号',
        name: 'number',
        type: String,
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
          name: '档案室1',
          cabinet:'11',
          floor:'上',
          number: '111'
        },
        {
          id: 2,
          name: '档案室2',
          cabinet:'11',
          floor:'下',
          number: '222'
        }
      ]
    },
    addData(val) {
      this.tableData.push(val)
    }
  }
})