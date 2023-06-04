<template>
  <div class="common-layout">
    <el-container>
      <el-aside width="200px">
        <Aside :menus="$store.menus" style="height: 95vh"></Aside>
      </el-aside>
      <el-container>
        <el-header>
          <TableHead :tableTitle="$store.tableTitle" :tableOperations="$store.tableOperations" :saveData="saveData"
            :addTitle="$store.addTitle" :dataitem="$store.dataitem" />
          <Search :filter="filter" class="search"></Search>
          <Edit class="edit"></Edit>
          <!-- <div class="filter">
            <Filter></Filter>
                  </div> -->
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
import Edit from '@/components/edit/Edit.vue'
import Aside from '@/components/aside/Aside.vue'
import MainTable from '@/components/MainTable.vue'
import ColumnFilter from '@/components/columnFilter/ColumnFilter.vue'
import Pagination from '@/components/pagination/Pagination.vue'
import Filter from '@/components/filter/Filter.vue'
import { useInfoStore } from '@/stores/archivesInfo'

const $store = useInfoStore()
//侧边栏
$store.asideData()
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
$store.editInfo()
provide('userData', $store.userData)
</script>

<style lang="scss" scoped>
.search {
  flex: 0 0 auto;
  /* 不伸缩、不收缩，固定高度 */
  float: right;
}

.form {
  flex: 1 0 auto;
  /* 可以伸缩、不收缩 */
  position: relative;
  display: flex;
  justify-content: center;
  /* 让内部元素水平居中 */
  align-items: center;

  /* 让内部元素垂直居中 */
  .maintable {
    position: absolute;
    text-align: center;
  }
}

.pagination {
  flex: 0 0 auto;
  /* 不伸缩、不收缩，固定高度 */
}

.footer {
  display: flex;
  justify-content: space-between;
  align-items: center;
}
.edit{
  margin-left: 80%;
}
</style>
