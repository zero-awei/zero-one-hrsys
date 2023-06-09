import { defineStore } from 'pinia'
import Request from '@/apis/request'

export const useCertificateInfoStore = defineStore('certificateinfo', {
  state: () => ({
    baseUrl:import.meta.env.VITE_HR_C2_2,
    tableTitle: '证书信息',
    tableOperations: [
      {
        name: '搜索'
      },
      {
        name:'新增'
      }
    ],
    xmlData: [
      { id: 1, name: '员工编号', prop: 'ygbh' },
      { id: 2, name: '员工姓名', prop: 'pimperSonName' },
      { id: 3, name: '员工状态', prop: 'ygzt' },
      { id: 4, name: '组织', prop: 'zz' },
      { id: 5, name: '证书编号', prop: 'zgzsbh' },
      { id: 6, name: '一建配套B证编号', prop: 'bcardNumber' },
      { id: 7, name: '证书名称', prop: 'pimVocationalName' },
      { id: 8, name: '证书类型', prop: 'zslx' },
      { id: 9, name: '签发日期', prop: 'zghqrq' },
      { id: 10, name: '签发机构', prop: 'zgsydw' },
      { id: 11, name: '注册单位', prop: 'zcdw' },
      { id: 12, name: '发证有效期', prop: 'fzyxq' },
      { id: 13, name: '失效日期', prop: 'sxrq' },
      { id: 14, name: '年审情况', prop: 'nsqk' },
      { id: 15, name: '使用情况', prop: 'syqk' },
      { id: 16, name: '变更情况', prop: 'alteration' },
      { id: 17, name: '员工唯一标识', prop: 'pimpersonid' },
      { id: 18, name: '证书注册编号', prop: 'regisnumber' },
      { id: 19, name: '社保缴纳单位', prop: 'socsecpayunit' },
      { id: 20, name: '初始注册时间', prop: 'cszcsj' },
      { id: 21, name: '续注册时间', prop: 'xzcsj' },
      { id: 22, name: '证书唯一标识', prop: 'pimvocationalid' },
    ],
    tableData: null,
    addTitle: '新建证书',
    dataitem:[
      {
        label: '员工编号',
        name: 'ygbh',
        type: String        
      },
      {
        label: '证书编号',
        name: 'zgzsbh',
        type: String        
      },
      {
        label: '一建配套B证编号',
        name: 'bcardNumber',
        type: String        
      },
      {
        label: '证书名称',
        name: 'pimVocationalName',
        type: String        
      },
      {
        label: '证书类型',
        name: 'zslx',
        type: String        
      },
      {
        label: '签发日期',
        name: 'zghqrq',
        type: String        
      },
      {
        label: '签发机构',
        name: 'zgsydw',
        type: String        
      },
      {
        label: '注册单位',
        name: 'zcdw',
        type: String        
      },
      {
        label: '失效日期',
        name: 'sxrq',
        type: String        
      },
      {
        label: '年审情况',
        name: 'nsqk',
        type: String        
      },
      {
        label: '使用情况',
        name: 'syqk',
        type: String        
      },
      {
        label: '变更情况',
        name: 'alteration',
        type: String        
      },
      {
        label: '员工唯一标识',
        name: 'pimpersonid',
        type: String        
      },
      {
        label: '证书注册编号',
        name: 'regisnumber',
        type: String        
      },
      {
        label: '社保缴纳单位',
        name: 'socsecpayunit',
        type: String        
      },
      {
        label: '初始注册时间',
        name: 'cszcsj',
        type: String        
      },
      {
        label: '续注册时间',
        name: 'xzcsj',
        type: String        
      },
    ],
    total: null
  }),
  actions: {
    async initTableData(pageSize,pageIndex) {
      let data = await Request.requestForm(
        Request.GET,
        this.baseUrl+'/query-CheckCerList',
        {
          "pageIndex": pageIndex,
          "pageSize": pageSize,
        },
        null
      )
      const rows = data.data.rows
      const totals=data.data.total
      this.total = totals
      this.tableData = rows
    },
    addData(val) {
      this.tableData.push(val)
    }
  }
})
