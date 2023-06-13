import Request from '@/apis/request'
import { defineStore } from 'pinia'

export const menuManageStore = defineStore('menuManage', {
  state: () => ({
    title: '菜单管理',
    options: [{ name: '搜索' }, { name: '新增' }, { name: '删除' }],
    tableData: null,
    dataitem: null,
    baseUrl: import.meta.env.VITE_HR_J1_3 + '/sys-menu',
    xmlData: [
      { id: 1, name: '菜单ID', prop: 'id' },
      { id: 2, name: '菜单名称', prop: 'name' },
      { id: 3, name: '路由地址', prop: 'path' },
      { id: 4, name: '显示级别', prop: 'level' },
      { id: 5, name: '菜单图标', prop: 'icon' },
      { id: 6, name: '父菜单名称', prop: 'parent_menu_id' },
      { id: 7, name: '菜单层次', prop: 'priority' },
      { id: 8, name: '菜单描述', prop: 'description' },
      { id: 9, name: '是否启用', prop: 'isEnable' }
      // { id: 10, name: 'creator', prop: 'creator' }
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
    //
    initDataItem() {
      this.dataitem = [
        {
          label: '菜单ID',
          name: 'id',
          type: Number
        },
        {
          label: '菜单名称',
          name: 'name',
          type: String
        },
        {
          label: '路由地址',
          name: 'path',
          type: String
        },
        {
          label: '显示级别',
          name: 'level',
          type: String
        },
        {
          label: '父菜单名称',
          name: 'parent_menu_id',
          type: String
        },
        {
          label: '菜单层次',
          name: 'priority',
          type: Number
        },
        {
          label: '菜单描述',
          name: 'description',
          type: String
        },
        {
          label: '是否启用',
          name: 'isEnable',
          type: String
        }
        // {
        //   label: 'creator',
        //   name: 'creator',
        //   type: String
        // }
      ]
    },
    addData(val) {
      this.tableData.push(val)
    }
  }
})
