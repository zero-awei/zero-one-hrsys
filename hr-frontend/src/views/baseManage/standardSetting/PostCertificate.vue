<template>
  <TableHead :tableTitle="tableTitle" :tableOperations ="tableOperations" :store="$store"/>
  <MainTable :xmlData="xmlData" :tableData="tableData"/>
</template>

<script setup>
import TableHead from '@/components/table/head/TableHead.vue'
import MainTable from '@/components/MainTable.vue'
import {usePostCertificateStore} from '@/stores/postCertificate'

const $store = usePostCertificateStore()
$store.initTableData()
const tableData = computed(()=>$store.getTableData)


const tableTitle = ref('岗位(技能)证书')
const tableOperations = reactive([
  {
    name:'新增'
  }
])
const xmlData = [
  { id: 1, name: '排序号', prop: 'id' },
  { id: 2, name: '岗位(技能)证书', prop: 'name' },
]



</script>

<style>

</style>