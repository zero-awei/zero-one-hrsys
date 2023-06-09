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
  
  <script  setup>
import TableHead from '@/components/table/head/TableHead.vue'
import MainTable from '@/components/MainTable.vue'
import ColumnFilter from '@/components/columnFilter/ColumnFilter.vue'
import Pagination from '@/components/pagination/Pagination.vue'
import { ref } from 'vue'
import { useTrianee } from '@/apis/roster'
const $store = useTrianee()
$store.getTrainee()
const saveData = (val) => {
  //写保存数据的逻辑
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