<template>
  <div>
    <TableHead :tableTitle="$store.title"> </TableHead>
    <div class="header">
      <SearchBox></SearchBox>
      <AddButton
        :addTitle="$store.title"
        :dataitem="$store.dataitem"
        :saveData="$store.addData"
      ></AddButton>
      <el-button>删除</el-button>
      <el-button>启用</el-button>
      <el-button>禁用</el-button>
    </div>
    <MainTable
      :xml-data="newXmlData"
      :table-data="$store.tableData"
    ></MainTable>
    <el-footer>
      <div class="footer">
        <ColumnFilter :xmlData="$store.xmlData" :parentMethod="getNewXmlData" />
        <Pagination :pageSizes="$store.pageSizes" :total="$store.total" />
      </div>
    </el-footer>
  </div>
</template>

<script lang="ts" setup>
import { ref } from 'vue'
import TableHead from '@/components/table/head/TableHead.vue'
import MainTable from '@/components/MainTable.vue'
import { onBeforeMount } from 'vue'
import { userManageStore } from '@/stores/userManage'
import SearchBox from '@/components/SearchBox.vue'
import AddButton from '@/components/table/head/AddButton.vue'

const $store = userManageStore()
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

<style scoped>
.header,
.footer {
  display: flex;
}
</style>
