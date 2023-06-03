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
import MainTable from '@/components/MainTable.vue'
import ColumnFilter from '@/components/columnFilter/ColumnFilter.vue'
import Pagination from '@/components/pagination/Pagination.vue'
// import Filter from '@/components/filter/Filter.vue'
import { useRecordStore } from '@/stores/fileTransferRecord'

const $store = useRecordStore()
//表格数据
$store.initTableData()
// 将新增的数据保存
const saveData = (val) => {
  $store.addData(val)
}
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
  /* 使用一个 flex 容器实现布局 */
  flex-direction: column;
  /* 竖直方向排列 */
  height: 100vh;
  /* 设置高度为视口高度，使布局充满整个屏幕 */
}

.search {
  flex: 0 0 auto;
  /* 不伸缩、不收缩，固定高度 */
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
