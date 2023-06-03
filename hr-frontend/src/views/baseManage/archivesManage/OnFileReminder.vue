<template>
  <div class="common-layout">
    <el-container>
      <el-aside width="200px">
        <!-- <Aside :menus="menus" style="height: 95vh"></Aside> -->
      </el-aside>
      <el-container>
        <el-header>
          <TableHead :tableTitle="$store.tableTitle" :addTitle="$store.addTitle" :tableOperations="$store.tableOperations" :dataitem="$store.dataitem" :saveData="saveData">
            <Search :filter="filter" class="search"></Search>
            <!-- <div class="filter">
              <Filter></Filter>
            </div> -->
          </TableHead>
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
import Filter from '@/components/filter/Filter.vue'
import { useOnReminderStore} from '@/stores/onFileReminder'

const $store = useOnReminderStore()
//侧边栏
$store.asideData()
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
const saveData = (val)=>{
  $store.addData(val)
}

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
