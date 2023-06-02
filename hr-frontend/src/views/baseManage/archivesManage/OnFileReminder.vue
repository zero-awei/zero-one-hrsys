<template>
  <div class="common-layout">
    <el-container>
      <el-aside width="200px">
        <Aside :menus="menus" style="height: 95vh"></Aside>
      </el-aside>
      <el-container>
        <el-header>
          <TableHead :tableTitle="$store.tableTitle" :addTitle="$store.addTitle" :tableOperations="$store.tableOperations" :saveData="$store.addData">
            <Search :filter="filter" class="search"></Search>
            <div class="filter">
              //导出

              <Filter></Filter>
            </div>
          </TableHead>
        </el-header>
        <el-main>
          <div class="table">
            <MainTable :tableData="$store.tableData" :xmlData="$store.newXmlData"></MainTable>
          </div>
        </el-main>
        <el-footer>
          <div class="footer">
            <ColumnFilter :xmlData="$store.xmlData" :parentMethod="$store.getNewXmlData">
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
import MainTable from '../../../components/MainTable.vue'
import ColumnFilter from '@/components/columnFilter/ColumnFilter.vue'
import Pagination from '@/components/pagination/Pagination.vue'
import Filter from '@/components/filter/Filter.vue'
import { useInfoStore } from '@/stores/archievesManage/archievesInfo.js'

const $store = useInfoStore()
//侧边栏
$store.asideData() 
//表格数据
$store.savaTableData()
$store.getNewXmlData(checkStatus)
//将新增的数据保存
// const saveData = (val)=>{
//   $store.addData(val)
// }

</script>

<style lang="scss" scoped>
.footer {
  display: flex;
  justify-content: space-between;
  align-items: center;
}
.filter {
  color: purple;
}
</style>
