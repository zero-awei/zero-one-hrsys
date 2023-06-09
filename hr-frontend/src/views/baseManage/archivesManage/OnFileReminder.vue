<template>
  <div class="common-layout">
    <el-container>
      <!-- <el-aside width="200px">
        <Aside :menus="menus" style="height: 95vh"></Aside>
      </el-aside> -->
      <el-container>
        <el-header>
          <TableHead :tableTitle="$store.tableTitle" :addTitle="$store.addTitle" :tableOperations="$store.tableOperations"
            :dataitem="$store.dataitem" :saveData="saveData" />
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
import MainTable from '../../../components/MainTable.vue'
import ColumnFilter from '@/components/columnFilter/ColumnFilter.vue'
import Pagination from '@/components/pagination/Pagination.vue'
import Filter from '@/components/filter/Filter.vue'
import { useOutReminderStore } from '@/stores/outFileReminder'
import { read, utils, writeFileXLSX } from 'xlsx'

const $store = useOutReminderStore()
// 全局事件总线
const mitt = getCurrentInstance().appContext.config.globalProperties.$bus
const rows=ref()

//侧边栏
// $store.asideData()
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
// 将新增的数据保存
const saveData = (val) => {
  $store.addData(val)
}

//过滤器
const controlShow = () => {
  $store.show = !$store.show
}
const res = $store.requestRes($store.data)
mitt.on('search', res)

//导出
onMounted(async () => {
  /* Download from https://sheetjs.com/pres.numbers */
  const f = await fetch('https://sheetjs.com/pres.numbers')
  const ab = await f.arrayBuffer()
  /* parse workbook */
  const wb = read(ab)
  /* update data */
  rows.value = utils.sheet_to_json(wb.Sheets[wb.SheetNames[0]])
})
/* get state data and export to XLSX */
function exportFile() {
  const ws = utils.json_to_sheet(rows.value)
  const wb = utils.book_new()
  utils.book_append_sheet(wb, ws, 'Data')
  writeFileXLSX(wb, 'SheetJSVueAoO.xlsx')
}
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

.filter {
  color: purple;
}
</style>
