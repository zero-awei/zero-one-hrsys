<template>
  <el-container>
    <el-header>
      <TableHead    
        :tableTitle="$store.tableTitle"
        :tableOperations="$store.tableOperations"
        :saveData="saveData"
        :addTitle="$store.addTitle"
        :dataitem="$store.dataitem"
      />
    </el-header>
    <el-main>
      <MainTable 
        :xmlData="newXmlData" 
        :tableData="$store.tableData" />
    </el-main>
    <el-footer>
      <div class="footer">
        <ColumnFilter :xmlData="$store.xmlData" :parentMethod="getNewXmlData" />
        <Pagination :pageSizes="$store.pageSizes" :total="$store.total" />
      </div>
    </el-footer>
  </el-container>
</template>

<script setup>
import TableHead from '@/components/table/head/TableHead.vue'
import MainTable from '../../../components/MainTable.vue'
import Search from '@/components/SearchBox.vue'
import Pagination from '@/components/pagination/Pagination.vue'
import 'element-plus/dist/index.css'
import { usePrivateAbroadStore } from '@/stores/privateAbroad'

const $store = usePrivateAbroadStore()
$store.initTableData()

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

<style lang="scss" scoped>
.footer {
  display: flex;
  justify-content: space-between;
  align-items: center;
}
</style>