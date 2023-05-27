<template>
  <TableHead :tableTitle="tableTitle" :tableOperations ="tableOperations" :saveData="saveData" :addTitle= "addTitle" :addData="addData"/>
  <MainTable :xmlData="xmlData" :tableData="$store.tableData"/>
</template>

<script setup>
import TableHead from '@/components/table/head/TableHead.vue'
import MainTable from '@/components/MainTable.vue'
import {usePostCertificateStore} from '@/stores/postCertificate'
import { ref } from 'vue'

const $store = usePostCertificateStore()
$store.initTableData()
// const tableData = computed(()=>$store.tableData)

const tableTitle = ref('岗位(技能)证书')
const addTitle = ref('岗位(技能)证书')
const tableOperations = reactive([
  {
    name:'新增'
  }
])
const xmlData = [
  { id: 1, name: '排序号', prop: 'id' },
  { id: 2, name: '岗位(技能)证书', prop: 'name' },
]

//将新增的数据保存
const saveData = (val)=>{
  $store.addData(val)
}

const addData = reactive([
  {
    label:'排序号',
    name:'id',
    type:Number,
  },
  {
    label:'岗位(技能)证书',
    name:'name',
    type:String,
  }  
])



</script>

<style>

</style>