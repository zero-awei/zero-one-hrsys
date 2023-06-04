import { defineStore } from 'pinia'

export const rightsManageStore = defineStore('rightsManage', {
  state: () => ({
    title: '权限管理',
    options: [{ name: '搜索' }, { name: '新增' }, { name: '过滤' }],
    tableData: null,
    dataitem: null,
    xmlData: [
      { id: 1, name: '权限ID', prop: 'id' },
      { id: 2, name: '权限名称', prop: 'name' },
      { id: 3, name: '链接地址', prop: 'url' },
      { id: 4, name: '显示级别', prop: 'level' },
      { id: 5, name: '父权限名称', prop: 'fatherName' },
      { id: 6, name: '层次', prop: 'cengci' },
      { id: 7, name: '描述', prop: 'description' },
      { id: 8, name: '是否启用', prop: 'isUse' },
      { id: 9, name: '操作', prop: 'operation' }
    ]
  }),
  actions: {
    initTableData() {
      this.tableData = [
        {
          id: 1,
          name: '修改',
          url: 'xxx',
          level: 'qwe',
          fatherName: '编辑',
          cengci: 1,
          description: 'sayoriqwq',
          isUse: '启用',
          operation: []
        },
        {
          id: 2,
          name: 'qweft',
          url: 'xxx',
          level: 'qwe',
          fatherName: '编辑',
          cengci: 1,
          description: 'sayoriqwq',
          isUse: '禁用',
          operation: []
        }
      ]
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
          name: 'url',
          type: String
        },
        {
          label: '显示级别',
          name: 'level',
          type: String
        },
        {
          label: '父权限名称',
          name: 'fatherName',
          type: String
        },
        {
          label: '层次',
          name: 'cengci',
          type: Number
        },
        {
          label: '描述',
          name: 'description',
          type: String
        },
        {
          label: '是否启用',
          name: 'isUse',
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
