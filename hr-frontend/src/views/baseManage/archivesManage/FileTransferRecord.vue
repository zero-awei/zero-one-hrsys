//例子
<template>
  <div class="common-layout">
    <el-container>
      <el-container>
        <el-header>
          <TableHead :tableTitle="$store.tableTitle" :tableOperations="$store.tableOperations" />
          <Search :filter="filter" class="search"></Search>
          <el-button @click="controlShow">
            过滤
            <Filter :data="$store.data" v-show="$store.show" class="filter">
            </Filter>
          </el-button>
          <el-button type="primary" @click="exportFile">导出</el-button>
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
            <Pagination :current-page="$store.currentPage" :page-size="$store.pageSize" :total="$store.tableData.length">
            </Pagination>
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
// 全局事件总线
const mitt = getCurrentInstance().appContext.config.globalProperties.$bus

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

//过滤器
const controlShow = () => {
  $store.show = !$store.show
}
const res = $store.requestRes($store.data)
mitt.on('search', res)
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
