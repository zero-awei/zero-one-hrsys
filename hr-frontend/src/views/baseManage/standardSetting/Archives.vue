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
      <Pagination :pageSizes="$store.pageSizes" :total="$store.total"/>
    </div>
  </div>
</template>

<script setup>
import TableHead from '@/components/table/head/TableHead.vue'
import MainTable from '@/components/MainTable.vue'
import Pagination from '@/components/pagination/Pagination.vue'
import {useArchivesStore} from '@/stores/archives'

const $store = useArchivesStore()
$store.initTableData()

//将新增的数据保存
const saveData = (val)=>{
  $store.addData(val)
}

</script>

<style>

</style>