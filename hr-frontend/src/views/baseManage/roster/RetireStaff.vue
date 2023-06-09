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
      <Pagination :total="$store.total" />
    </div>
  </div>
</template>

<script lang="ts" setup>
import TableHead from '@/components/table/head/TableHead.vue'
import Pagination from '@/components/pagination/Pagination.vue'
import MainTable from '@/components/MainTable.vue'
import { getCurrentInstance, onBeforeMount, onMounted, ref } from 'vue'
import { RetireStaffStore } from '@/stores/retirement'

//处理页码
const $store = RetireStaffStore()
const { $bus } = getCurrentInstance().appContext.config.globalProperties
let pageSize = 10
let currentPage = 1
onBeforeMount(() => {
  $store.initTableData(pageSize, currentPage)
})

onMounted(() => {
  $bus.on('getPageSize', (data) => {
    pageSize = data.value
    $store.initTableData(pageSize, currentPage)
  })
  $bus.on('getCurrentPage', (data) => {
    currentPage = data.value
    $store.initTableData(pageSize, currentPage)
  })
})

//选择列逻辑
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
