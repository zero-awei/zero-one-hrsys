import Request from '@/apis/request'
import { defineStore } from 'pinia'

export const userManageStore = defineStore('userManage', {
  state: () => ({
    title: '用户管理',
    options: [{ name: '搜索' }, { name: '新增' }, { name: '删除' }],
    tableData: null,
    dataitem: null,
    baseUrl: import.meta.env.VITE_HR_J1_3 + '/sys-user',
    xmlData: [
      { id: 1, name: '序号', prop: 'id' },
      { id: 2, name: '用户名', prop: 'username' },
      { id: 3, name: '密码', prop: 'password' },
      { id: 4, name: '角色', prop: 'role' },
      { id: 5, name: '邮箱', prop: 'mail' },
      { id: 6, name: '电话', prop: 'phone' },
      { id: 7, name: '注册时间', prop: 'registTime' },
      { id: 8, name: '状态', prop: 'isEnable' }
    ],
    //分页器
    total: 1000
    // pageSizes:[]
  }),
  actions: {
    async initTableData(pageSize, pageIndex) {
      let data = await Request.requestForm(
        Request.GET,
        this.baseUrl + '/query_all',
        {
          pageIndex: pageIndex,
          pageSize: pageSize
        },
        null
      )
      const rows = data.data.rows
      this.tableData = rows
    },
    initDataItem() {
      this.dataitem = [
        {
          label: '序号',
          name: 'id',
          type: Number
        },
        {
          label: '用户名',
          name: 'username',
          type: String
        },
        {
          label: '密码',
          name: 'password',
          type: String
        },
        {
          label: '角色',
          name: 'role',
          type: String
        },
        {
          label: '邮箱',
          name: 'mail',
          type: String
        },
        {
          label: '电话',
          name: 'phone',
          type: String
        },
        {
          label: '注册时间',
          name: 'registTime',
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
