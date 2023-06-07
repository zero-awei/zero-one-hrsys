import { defineStore } from 'pinia'
import Request from '../request'
const BaseUrl = '/bas'

export const useRoster = defineStore('roster', {
  state: () => ({
    tableTitle: '人员花名册',
    tableOperations: [
      {
        name: '搜索'
      },
    ],
    xmlData: [
      { id: 1, name: '员工编号', prop: 'id' },
      { id: 2, name: '员工姓名', prop: 'name' },
      { id: 3, name: '组织', prop: 'organization' },
      { id: 4, name: '部门', prop: 'department' },
      { id: 5, name: '职务', prop: 'position' },
      { id: 6, name: '岗位', prop: 'job' },
      { id: 7, name: '证件号码', prop: 'certificateId' },
      { id: 8, name: '出生日期', prop: 'dateOfbrith' },
      { id: 9, name: '年龄', prop: 'age' },
      { id: 10, name: '手机号码', prop: 'phoneNumber' },
      { id: 11, name: '员工状态', prop: 'state' }
    ],
    tableData: null,
    pageSizes: ['10', '20'],
    total: 40,
    addTitle: '人员花名册',
    dataitem: [
      {
        label: '员工姓名',
        name: 'name',
        type: String
      },
      {
        label: '员工编号',
        name: 'ID',
        type: Array,
        //如果是选项请配置以下属性
        options: [
          {
            id: 1,
            optionData: '111'
          },
          {
            id: 2,
            optionData: '222'
          }
        ]
      },
      {
        label: '备注',
        name: 'remark',
        type: 'Text'
      }
    ]
  }),
  actions: {
    getRoster() {
      // let data=Request.requestForm(Request.Get,BaseUrl + 'query-employPage', data)
      // .then((data) => {
      //     // 记录Token到本地
      //     if (data.data) {
      //       $store.setToken(data.data)
      //       // 执行成功回调
      //       success()
      //       return
      //     }
      //     // 执行失败回调
      //     fail()
      //   })
      //   .catch((err) => {
      //     // 打印错误信息
      //     console.warn(err)
      //     // 执行失败回调
      //     fail()
      //   });
      this.tableData = [
        {
          id: 10001,
          name: '彭于晏',
          age: 26,
          sex:'男'
        },
        {
          id: 10002,
          name: '彭于晏',
          age: 22,
          sex:'女'
        }
      ]
    },
    addData(val) {
      this.tableData.push(val)
    }
  }
})
export const useTrianee = defineStore('trainee', {
  state: () => ({
    tableTitle: '见习员工',
    tableOperations: [
      {
        name: '搜索'
      },
      {
        name:'删除'
      },
      {
        name:'新增'
      }
    ],
    xmlData: [
      { id: 1, name: '员工编号', prop: 'id' },
      { id: 2, name: '员工姓名', prop: 'name' },
      { id: 3, name: '组织', prop: 'organization' },
      { id: 4, name: '部门', prop: 'department' },
      { id: 5, name: '职务', prop: 'position' },
      { id: 6, name: '岗位', prop: 'job' },
      { id: 7, name: '证件号码', prop: 'certificateId' },
      { id: 8, name: '出生日期', prop: 'dateOfbrith' },
      { id: 9, name: '年龄', prop: 'age' },
      { id: 10, name: '手机号码', prop: 'phoneNumber' },
      { id: 11, name: '员工状态', prop: 'state' }
    ],
    tableData: null,
    pageSizes: ['10', '20'],
    total: 30,
    addTitle: '见习员工',
    dataitem: [
      {
        label: '员工姓名',
        name: 'name',
        type: String
      },
      {
        label: '员工编号',
        name: 'ID',
        type: Array,
        //如果是选项请配置以下属性
        options: [
          {
            id: 1,
            optionData: '111'
          },
          {
            id: 2,
            optionData: '222'
          }
        ]
      },
      {
        label: '备注',
        name: 'remark',
        type: 'Text'
      }
    ]
  }),
  actions: {
    getTrainee() {
      // let data=Request.requestForm(Request.Get,BaseUrl + 'query-RraineePageQueryEmployeeList', data)
      // .then((data) => {
      //     // 记录Token到本地
      //     if (data.data) {
      //       $store.setToken(data.data)
      //       // 执行成功回调
      //       success()
      //       return
      //     }
      //     // 执行失败回调
      //     fail()
      //   })
      //   .catch((err) => {
      //     // 打印错误信息
      //     console.warn(err)
      //     // 执行失败回调
      //     fail()
      //   });
      this.tableData = [
        {
          id: 10001,
          name: '彭于晏',
          age: 26,
          organization: '集团总部',
          department: '企业部门',
          position: '总规划师',
          job: '培训管理',
          certificateId: 14082119910301,
          phoneNumber: 15035052120,
          state: '在职'
        },
        {
          id: 10002,
          name: '甄子丹',
          age: 26,
          organization: '集团总部',
          department: '企业部门',
          position: '总规划师',
          job: '培训管理',
          certificateId: 14082119910301,
          phoneNumber: 15035052120,
          state: '在职'
        }
      ]
    },
    addData(val) {
      this.tableData.push(val)
    }
  }
})
export const useInformation = defineStore('employee', {
  state: () => ({
    tableTitle: '员工信息',
    tableOperations: [
      {
        name: '搜索'
      },
      {
        name:'新增'
      }
    ],
    xmlData: [
      { id: 1, name: '员工编号', prop: 'id' },
      { id: 2, name: '员工姓名', prop: 'name' },
      { id: 3, name: '组织', prop: 'organization' },
      { id: 4, name: '部门', prop: 'department' },
      { id: 5, name: '职务', prop: 'position' },
      { id: 6, name: '岗位', prop: 'job' },
      { id: 7, name: '证件号码', prop: 'certificateId' },
      { id: 8, name: '出生日期', prop: 'dateOfbrith' },
      { id: 9, name: '年龄', prop: 'age' },
      { id: 10, name: '手机号码', prop: 'phoneNumber' },
      { id: 11, name: '员工状态', prop: 'state' }
    ],
    tableData: null,
    pageSizes: ['10', '20'],
    total: 30,
    addTitle: '员工信息',
    dataitem: [
      {
        label: '员工姓名',
        name: 'name',
        type: String
      },
      {
        label: '员工编号',
        name: 'ID',
        type: Array,
        //如果是选项请配置以下属性
        options: [
          {
            id: 1,
            optionData: '111'
          },
          {
            id: 2,
            optionData: '222'
          }
        ]
      },
      {
        label: '备注',
        name: 'remark',
        type: 'Text'
      }
    ]
  }),
  actions: {
    getInformation() {
      // let data=Request.requestForm(Request.Get,BaseUrl + 'query-RraineePageQueryEmployeeList', data)
      // .then((data) => {
      //     // 记录Token到本地
      //     if (data.data) {
      //       $store.setToken(data.data)
      //       // 执行成功回调
      //       success()
      //       return
      //     }
      //     // 执行失败回调
      //     fail()
      //   })
      //   .catch((err) => {
      //     // 打印错误信息
      //     console.warn(err)
      //     // 执行失败回调
      //     fail()
      //   });
      this.tableData = [
        {
          id: 10001,
          name: '彭于晏',
          age: 26,
          organization: '集团总部',
          department: '企业部门',
          position: '总规划师',
          job: '培训管理',
          certificateId: 14082119910301,
          phoneNumber: 15035052120,
          state: '在职'
        },
        {
          id: 10002,
          name: '甄子丹',
          age: 26,
          organization: '集团总部',
          department: '企业部门',
          position: '总规划师',
          job: '培训管理',
          certificateId: 14082119910301,
          phoneNumber: 15035052120,
          state: '在职'
        }
      ]
    },
    addData(val) {
      this.tableData.push(val)
    }
  }
})