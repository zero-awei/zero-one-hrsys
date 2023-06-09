import { defineStore } from 'pinia'

export const userManageStore = defineStore('userManage', {
  state: () => ({
    title: '用户管理',
    tableData: null,
    dataitem: null,
    xmlData: [
      { id: 1, name: '序号', prop: 'id' },
      { id: 2, name: '用户名', prop: 'username' },
      { id: 3, name: '密码', prop: 'password' },
      { id: 4, name: '角色', prop: 'role' },
      { id: 5, name: '邮箱', prop: 'email' },
      { id: 6, name: '电话', prop: 'phoneNumber' },
      { id: 7, name: '注册时间', prop: 'registerTime' },
      { id: 8, name: '状态', prop: 'state' },
      { id: 9, name: '操作', prop: 'operation' }
    ],
    pageSizes: ['10', '20'],
    total: 100
  }),
  actions: {
    initTableData() {
      this.tableData = [
        {
          id: 1,
          username: '李四',
          password: 'qwerdf',
          role: '管理员',
          email: 'xxxxx',
          phoneNumber: 'xxxxxx',
          registerTime: 'xxxxxx',
          state: true,
          operation: []
        },
        {
          id: 2,
          username: '李似',
          password: 'qwerdf',
          role: '管理员',
          email: 'xxxxx',
          phoneNumber: 'xxxxxx',
          registerTime: 'xxxxxx',
          state: true,
          operation: []
        }
      ]
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
          name: 'email',
          type: String
        },
        {
          label: '电话',
          name: 'phoneNumber',
          type: String
        },
        {
          label: '注册时间',
          name: 'registerTime',
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
