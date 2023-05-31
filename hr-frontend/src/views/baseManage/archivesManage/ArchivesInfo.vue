//例子
<template>
  <div class="common-layout">
    <el-container>
      <el-aside width="200px"><Aside></Aside></el-aside>
      <el-container>
        <el-header>
          <SearchBox :filter="filter"></SearchBox>
          <AddButton></AddButton>
          <TableHead :tableTitle="tableTitle" 
             :addTitle="addTitle" 
             :tableOperations ="tableOperations" 
             :dataitem="dataitem"
             :saveData="saveData"></TableHead>
        </el-header>
        <el-main><MainTable :tableData="tableData" :xmlData="xmlData"></MainTable></el-main>
        <el-footer><Pagination :pageSizes="pageSizes" :total="total"></Pagination></el-footer>
      </el-container>
    </el-container>
  </div>
</template>

<script setup>
import TableHead from '@/components/table/head/TableHead.vue'
import AddButton from '@/components/table/head/AddButton.vue'
import SearchBox from '@/components/SearchBox .vue'
import Filter from '@/components/Filter.vue'
import Aside from '@/componentns/aside/Aside.vue'
import MainTable from '@/components/MainTable.vue'
import Pagination from '@/components/pagination/Pagination.vue'
import Employees from '@/components/Employees/Employees.vue'
import Edit from '@/components/edit/Edit.vue'
import MessageBox from '@/components/feedback/MessageBox.vue'
import Notification from '@/components/feedback/Notification.vue'
import {useInfoStore} from '@/stores/archievesManage/archievesInfo.js'

const $store = useInfoStore()
//侧边栏
$store.asideData()
//搜索框
$store.filter
//过滤器-待定
//表格数据
$store.savaTableData()
//保存新增的数据
const saveData = (val)=>{
  $store.getData(val)
}
//编辑信息


</script>

<style></style>
