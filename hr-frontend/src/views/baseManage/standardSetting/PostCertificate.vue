<template>
  <div>
    <div class="header">
      <TableHead :tableTitle="$store.tableTitle" 
                :tableOperations ="$store.tableOperations" 
                :saveData="saveData" 
                :addTitle= "$store.addTitle" 
                :dataitem="$store.dataitem"
                :deleteData="deleteData"
      />
    </div>
    <div class="table">
      <MainTable :xmlData="newXmlData" :tableData="$store.tableData"/>
    </div>
    <div class="footer">
      <ColumnFilter :xmlData="$store.xmlData" :parentMethod="getNewXmlData"/>
      <Pagination :pageSizes="$store.pageSizes" :total="$store.total"/>
    </div>
  </div>
</template>

<script setup>
import TableHead from '@/components/table/head/TableHead.vue'
import MainTable from '@/components/MainTable.vue'
import ColumnFilter from '@/components/columnFilter/ColumnFilter.vue'
import Pagination from '@/components/pagination/Pagination.vue'
import {usePostCertificateStore} from '@/stores/postCertificate'
import { onBeforeMount } from 'vue'

const $store = usePostCertificateStore()
//页面挂载前请求数据
onBeforeMount(()=>{
  $store.loadTableData()
})

//将新增的数据保存
const saveData = (val)=>{
  $store.addData(val)
}
//书写数据删除逻辑
const deleteData = (val)=>{
  console.log(val)
}

function getNewXmlData(checkStatus) {
  newXmlData.value = $store.xmlData.filter((item) => {
    return checkStatus.value.includes(item.name)
  })
}
const newXmlData = ref([])
newXmlData.value = [...$store.xmlData]

</script>

<style lang="scss" scoped>
.footer{
  display: flex;
  justify-content: space-between;
  align-items: center;
}
</style>