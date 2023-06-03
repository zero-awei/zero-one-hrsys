import { defineStore } from 'pinia'

export const useCertificateInfoStore = defineStore('certificateinfo', {
    state: () => ({
        tableTitle: '证书信息',
        tableOperations: [
            {
                name: '搜索'
            },
        ],
        xmlData: [
            { id: 1, name: '员工编号', prop: 'id' },
            { id: 2, name: '员工姓名', prop: 'name' },
            { id: 3, name: '员工状态', prop: 'state' },
            { id: 4, name: '组织', prop: 'organization' },
            { id: 5, name: '证书编号', prop: 'certificateNo' },
            { id: 6, name: '一建配套B证编号', prop: 'firstClassConstructorBNo' },
            { id: 7, name: '证书名称', prop: 'certificateName' },
            { id: 8, name: '证书类型', prop: 'certificateType' },
            { id: 9, name: '签发日期', prop: 'issueDate' },
            { id: 10, name: '签发机构', prop: 'issueAuthority' },
            { id: 11, name: '注册单位', prop: 'registeredUnit' },
            { id: 12, name: '发证有效期', prop: 'validityPeriod' },
            { id: 13, name: '失效日期', prop: 'expirationDate' },
            { id: 14, name: '证书剩余天数', prop: 'remainingDay' },
        ],
        tableData: null,
        pageSizes: ['10', '20'],
        total: 1000
    }),
    actions: {
        initTableData() {
            this.tableData = [
                {
                    id: 1,
                    name: '施工员'
                },
                {
                    id: 2,
                    name: '安全员'
                }
            ]
        },
        addData(val) {
            this.tableData.push(val)
        }
    }
})