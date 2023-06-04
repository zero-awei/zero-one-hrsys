//例子
<template>
  <div class="common-layout">
    <el-container>
      <el-container>
        <el-header>
          <TableHead :tableTitle="$store.tableTitle" :tableOperations="$store.tableOperations"/>
          <Search :filter="filter" class="search"></Search>
        </el-header>
        <el-main>
          <div class="table">
            <MainTable :tableData="$store.tableData" :xmlData="newXmlData"></MainTable>
          </div>
        </el-main>
        <el-footer>
          <div class="footer">
            <ColumnFilter :xmlData="$store.xmlData" :parentMethod="getNewXmlData">
            </ColumnFilter>
            <Pagination></Pagination>
          </div>
        </el-footer>
      </el-container>
    </el-container>
  </div>
</template>

<script setup>
import TableHead from '@/components/table/head/TableHead.vue'
import Search from '@/components/SearchBox.vue'
import Aside from '@/components/aside/Aside.vue'
import MainTable from '@/components/MainTable.vue'
import ColumnFilter from '@/components/columnFilter/ColumnFilter.vue'
import Pagination from '@/components/pagination/Pagination.vue'
// import Filter from '@/components/filter/Filter.vue'
import { useRecordStore } from '@/stores/fileTransferRecord'

const $store = useRecordStore()
//表格数据
$store.initTableData()
//获取新表单数据
function getNewXmlData(checkStatus) {
  newXmlData.value = $store.xmlData.filter((item) => {
    return checkStatus.value.includes(item.name)
  })
}
const newXmlData = ref([])
newXmlData.value = [...$store.xmlData]
</script>

<style lang="scss" scoped>
.container {
  display: flex;
  flex-direction: column;
  height: 100vh;
}

.search {
  flex: 0 0 auto;
  float: right;
}

.maintable {
  position: absolute;
}

.footer {
  position: relative;
  margin-top: 35%;
  display: flex;
  justify-content: space-between;
  align-items: center;
}
</style>
