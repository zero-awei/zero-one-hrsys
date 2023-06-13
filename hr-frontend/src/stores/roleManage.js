import Request from '@/apis/request'
import { defineStore } from 'pinia'

export const roleManageStore = defineStore('roleManage', {
  state: () => ({
    title: '角色管理',
    options: [{ name: '搜索' }, { name: '新增' }, { name: '过滤' }],
    tableData: null,
    dataitem: null,
    baseUrl: import.meta.env.VITE_HR_J1_3 + '/sys-role',
    xmlData: [
      { id: 1, name: '角色ID', prop: 'id' },
      { id: 2, name: '角色名称', prop: 'name' },
      { id: 3, name: '关键词', prop: 'keyword' },
      { id: 4, name: '角色描述', prop: 'description' },
      { id: 5, name: '状态', prop: 'isEnable' }
    ]
  }),
  actions: {
    async initTableData() {
      let data = await Request.requestForm(
        Request.GET,
        this.baseUrl + '/query-one',
        {
          id: '1'
        },
        null
      )
      const rows = data.data.rows
      this.tableData = rows
    },
    initDataItem() {
      this.dataitem = [
        {
          label: '角色ID',
          name: 'id',
          type: String
        },
        {
          label: '角色名称',
          name: 'name',
          type: String
        },
        {
          label: '关键词',
          name: 'keyword',
          type: String
        },
        {
          label: '角色描述',
          name: 'description',
          type: String
        },
        {
          label: '状态',
          name: 'isEnable',
          type: Number
        }
      ]
    },
    addData(val) {
      this.tableData.push(val)
    }
  }
})
