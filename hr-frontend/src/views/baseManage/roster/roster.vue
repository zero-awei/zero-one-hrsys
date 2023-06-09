<template>
  <div class="header">
    <TableHead
      :tableTitle="$store.tableTitle"
      :tableOperations="$store.tableOperations"
      :saveData="saveData"
      :addTitle="$store.addTitle"
      :dataitem="$store.dataitem"
    />
  </div>
  <div class="table">
    <MainTable :xmlData="newXmlData" :tableData="$store.tableData" />
  </div>
  <div class="footer">
    <ColumnFilter :xmlData="$store.xmlData" :parentMethod="getNewXmlData" />
    <Pagination :pageSizes="$store.pageSizes" :total="$store.total" />
  </div>
</template>
  
<script setup>
import TableHead from '@/components/table/head/TableHead.vue'
import MainTable from '@/components/MainTable.vue'
import Pagination from '@/components/pagination/Pagination.vue'
import ColumnFilter from '@/components/columnFilter/ColumnFilter.vue'
import 'element-plus/dist/index.css'
import { ref } from 'vue'
import { useRoster } from '@/apis/roster'
const $store = useRoster()
$store.getRoster()
//将新增的数据保存
const saveData = (val) => {
  $store.addData(val)
}
function getNewXmlData(checkStatus) {
  newXmlData.value = $store.xmlData.filter((item) => {
    return checkStatus.value.includes(item.name)
  })
}
const newXmlData = ref([])
newXmlData.value = [...$store.xmlData]
</script>
  
<style scoped lang="scss">
.footer {
  display: flex;
  justify-content: space-between;
  align-items: center;
}
</style>