<template>
  <div>
    <TableHead
      :tableTitle="$store.title"
      :addTitle="$store.title"
      :tableOperations="$store.options"
      :dataitem="$store.dataitem"
      :saveData="$store.addData"
    >
    </TableHead>
    <MainTable
      :xml-data="$store.xmlData"
      :table-data="$store.tableData"
    ></MainTable>
  </div>
</template>

<script lang="ts" setup>
import TableHead from '@/components/table/head/TableHead.vue'
import MainTable from '@/components/MainTable.vue'
import { onBeforeMount } from 'vue'
import { roleManageStore } from '@/stores/roleManage'

const $store = roleManageStore()
onBeforeMount(() => {
  $store.initTableData()
  $store.initDataItem()
})
</script>

<style></style>
