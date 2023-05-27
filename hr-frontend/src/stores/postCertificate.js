import { defineStore } from 'pinia'

export const usePostCertificateStore = defineStore('postCertificate',{
    state:()=>({
        tableData:[
            {
                id:1,
                name:'施工员'
            },
            // {
            //     id:2,
            //     name:'安全员'
            // }
        ]
    }),
    actions:{
        initTableData(){
            this.tableData = [
                {
                    id:1,
                    name:'施工员'
                },
                {
                    id:2,
                    name:'安全员'
                }
            ]
        },
        addData(val){
            this.tableData.push(val)
        }
    },
    getters:{
        getTableData(){
            return this.tableData
        }
    }
})