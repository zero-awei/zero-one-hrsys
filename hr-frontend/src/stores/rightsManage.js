import Request from '@/apis/request'
import { defineStore } from 'pinia'

export const rightsManageStore = defineStore('rightsManage', {
  state: () => ({
    title: '权限管理',
    options: [{ name: '搜索' }, { name: '新增' }, { name: '删除' }],
    tableData: null,
    dataitem: null,
    baseUrl: import.meta.env.VITE_HR_J1_3 + '/sys-right',
    xmlData: [
      { id: 1, name: '权限ID', prop: 'id' },
      { id: 2, name: '权限名称', prop: 'name' },
      { id: 3, name: '链接地址', prop: 'linkUrl' },
      { id: 4, name: '显示级别', prop: 'level' },
      { id: 5, name: '父权限名称', prop: 'parentRightId' },
      { id: 6, name: '层次', prop: 'priority' },
      { id: 7, name: '描述', prop: 'description' },
      { id: 8, name: '是否启用', prop: 'isEnable' },
      { id: 9, name: '操作', prop: 'operation' }
    ]
  }),
  actions: {
    async initTableData() {
      let data = await Request.requestForm(
        Request.GET,
        this.baseUrl + '/query-list',
        {
          pageIndex: 1,
          pageSize: 10
        },
        null
      )
      const rows = data.data.rows
      this.tableData = rows
    },
    initDataItem() {
      this.dataitem = [
        {
          label: '权限ID',
          name: 'id',
          type: Number
        },
        {
          label: '权限名称',
          name: 'name',
          type: String
        },
        {
          label: '链接地址',
          name: 'linkUrl',
          type: String
        },
        {
          label: '显示级别',
          name: 'level',
          type: String
        },
        {
          label: '父权限名称',
          name: 'parentRightId',
          type: String
        },
        {
          label: '层次',
          name: 'priority',
          type: Number
        },
        {
          label: '描述',
          name: 'description',
          type: String
        },
        {
          label: '是否启用',
          name: 'isEnable',
          type: String
        },
        {
          label: '操作',
          name: 'operation',
          type: Array
        }
      ]
    },
    addData(val) {
      this.tableData.push(val)
    }
  }
})
