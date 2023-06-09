import { defineStore } from 'pinia'

export const roleManageStore = defineStore('roleManage', {
  state: () => ({
    title: '菜单管理',
    options: [{ name: '搜索' }, { name: '新增' }, { name: '过滤' }],
    tableData: null,
    dataitem: null,
    xmlData: [
      { id: 1, name: '角色ID', prop: 'id' },
      { id: 2, name: '角色名称', prop: 'name' },
      { id: 3, name: '关键词', prop: 'keyword' },
      { id: 4, name: '角色描述', prop: 'description' },
      { id: 5, name: '状态', prop: 'state' },
      { id: 6, name: '操作', prop: 'operation' }
    ]
  }),
  actions: {
    initTableData() {
      this.tableData = [
        {
          id: 1,
          name: '管理员',
          keyword: 'ADMIN',
          description: '管理员',
          state: true,
          operation: []
        },
        {
          id: 2,
          name: '管理',
          keyword: 'ADMN',
          description: '管理',
          state: true,
          operation: []
        }
      ]
    },
    initDataItem() {
      this.dataitem = [
        {
          label: '角色ID',
          name: 'id',
          type: Number
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
          name: 'state',
          type: Boolean
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
