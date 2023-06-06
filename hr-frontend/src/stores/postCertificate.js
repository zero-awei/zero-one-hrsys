import { defineStore } from 'pinia'
import Request from '@/apis/request'

export const usePostCertificateStore = defineStore('postCertificate', {
    state: () => ({
        tableTitle: '岗位(技能)证书',
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
            { id: 1, name: '排序号', prop: 'seialno' },
            { id: 2, name: '岗位(技能)证书', prop: 'pimqualtypename' },
        ],
        tableData: null,
        addTitle: '岗位(技能)证书',
        dataitem: [
            {
                label: '排序号',
                name: 'seialno',
                type: Number,
            },
            {
                label: '岗位(技能)证书',
                name: 'pimqualtypename',
                type: String,
            }
        ],
        pageSizes: ['10', '20'],
        total: 1000
    }),
    actions: {
        async loadTableData() {
            // //发送获取当前表格数据的请求
            // let data = await Request.requestForm(
            //   Request.GET,
            //   '/certificate/query-certificate',
            //   {
            //     "pageIndex": 1,
            //     "pageSize": 10,
            //   },
            //   null
            // )
            // const rows = data.data.rows
            const rows = [
                {
                    seialno: 1,
                    pimqualtypename: '施工员'
                },
                {
                    seialno: 2,
                    pimqualtypename: '安全员'
                }
            ]
            this.tableData = rows
        },
        addData(val) {
            this.tableData.push(val)
        }
    }
})