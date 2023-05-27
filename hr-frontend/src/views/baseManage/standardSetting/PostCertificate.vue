<template>
  <div>
    <div>
      <TableHead :tableTitle="$store.tableTitle" 
                :tableOperations ="$store.tableOperations" 
                :saveData="saveData" 
                :addTitle= "$store.addTitle" 
                :dataitem="$store.dataitem"
      />
    </div>
    <div>
      <MainTable :xmlData="$store.xmlData" :tableData="$store.tableData"/>
    </div>
    <div>
      <Pagination/>
    </div>
  </div>
</template>

<script setup>
import TableHead from '@/components/table/head/TableHead.vue'
import MainTable from '@/components/MainTable.vue'
import Pagination from '@/components/pagination/Pagination.vue'
import {usePostCertificateStore} from '@/stores/postCertificate'

const $store = usePostCertificateStore()
$store.initTableData()

//将新增的数据保存
const saveData = (val)=>{
  $store.addData(val)
}

</script>

<style>

</style>