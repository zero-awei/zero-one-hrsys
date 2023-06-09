<template>
  <div>
    <div class="header">
      <TableHead
        :tableTitle="$store.title"
        :tableOperations="$store.options"
        :saveData="addData"
        :addTitle="$store.title"
        :dataitem="$store.dataitem"
      />
    </div>
    <div class="table">
      <MainTable :xmlData="$store.xmlData" :tableData="$store.tableData" />
    </div>
  </div>
</template>

<script lang="ts" setup>
import TableHead from '@/components/table/head/TableHead.vue'
import MainTable from '@/components/MainTable.vue'
import { rightsManageStore } from '@/stores/rightsManage'
import { addRights } from '@/apis/sysManage/rightsManage'
import { onBeforeMount } from 'vue'
const $store = rightsManageStore()
onBeforeMount(() => {
  $store.initTableData()
  $store.initDataItem()
})

//将新增的数据保存
const addData = (val) => {
  addRights(
    val,
    () => {
      $store.initTableData()
      ElMessage.success('添加成功')
    },
    () => {
      ElMessage.error('添加失败')
    }
  )
}
</script>

<style></style>
