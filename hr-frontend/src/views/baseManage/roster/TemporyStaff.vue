<template>
  <div>
    <div class="header">
      <TableHead
        :tableTitle="$store.title"
        :tableOperations="$store.options"
        :saveData="$store.addData"
        :addTitle="$store.title"
        :dataitem="$store.dataitem"
      />
    </div>
    <div class="table">
      <MainTable :xmlData="newXmlData" :tableData="$store.tableData" />
    </div>
    <div class="footer">
      <ColumnFilter :xmlData="$store.xmlData" :parentMethod="getNewXmlData" />
      <Pagination
        :currentPage="$store.pageIndex"
        :pageSize="$store.pageSize"
        :total="$store.total"
      />
    </div>
  </div>
</template>

<script lang="ts" setup>
import TableHead from '@/components/table/head/TableHead.vue'
import Pagination from '@/components/pagination/Pagination.vue'
import MainTable from '@/components/MainTable.vue'
import { TemporaryStaffStore } from '@/stores/temporyStaff'
import { onBeforeMount, ref } from 'vue'

const $store = TemporaryStaffStore()

onBeforeMount(() => {
  $store.initTableData()
  $store.initDataItem()
})
function getNewXmlData(checkStatus) {
  newXmlData.value = $store.xmlData.filter((item) => {
    return checkStatus.value.includes(item.name)
  })
}
const newXmlData = ref([])
newXmlData.value = [...$store.xmlData]
</script>

<style>
.footer {
  display: flex;
  justify-content: space-between;
  align-items: center;
}
</style>
