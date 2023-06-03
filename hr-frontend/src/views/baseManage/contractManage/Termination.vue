<template>
  <div>
    <div class="header">
      <TableHead :tableTitle="$store.tableTitle" 
                :tableOperations ="$store.tableOperations" 
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
import {useTerminationStore} from '@/stores/termination'

const $store = useTerminationStore()
$store.initTableData()


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