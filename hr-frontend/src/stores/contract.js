import { defineStore } from 'pinia'
import Request from '@/apis/request'

export const useContractStore = defineStore('contract', {
    state: () => ({
        baseUrl: import.meta.env.VITE_HR_C6_1 + '/contract-management',
        tableTitle: '合同信息',
        tableOperations: [
            {
                name: '搜索'
            },
            {
                name: '新增'
            },
            {
                name: '删除'
            }
        ],
        xmlData: [
            { id: 1, name: '员工编号', prop: 'personid' },
            { id: 2, name: '员工姓名', prop: 'name' },
            { id: 3, name: '员工所属单位', prop: 'person_department' },
            { id: 4, name: '员工状态', prop: 'person_condition' },
            { id: 5, name: '到本单位时间', prop: 'date_arrive' },
            { id: 6, name: '合同编号', prop: 'id' },
            { id: 7, name: '合同签订单位', prop: 'department_c' },
            { id: 8, name: '合同类别', prop: 'type' },
            { id: 9, name: '合同类型', prop: 'variety' },
            { id: 10, name: '起始时间', prop: 'date' },
            { id: 11, name: '结束时间', prop: 'date_end' },
            { id: 12, name: '合同状态', prop: 'condition' },
            { id: 13, name: '合同剩余天数', prop: 'date_over' },
            { id: 14, name: '试用到期天数', prop: 'rest' }
        ],
        tableData: null,
        addTitle: '合同信息',
        dataitem: [
            {
                label: '公司名称',
                name: 'name',
                type: String
            },
        ],
        total: null
    }),
    actions: {
        async initTableData(pageSize, pageIndex) {
            let data = await Request.requestForm(
                Request.GET,
                this.baseUrl + '/query-contract',
                {
                    "pageIndex": pageIndex,
                    "pageSize": pageSize,
                    "row_show": 1111111
                },
                null
            )
            const rows = data.data.rows
            const totals = data.data.total
            this.total = totals
            this.tableData = rows
        },
    }
})