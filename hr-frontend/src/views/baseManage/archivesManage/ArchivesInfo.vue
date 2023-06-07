<template>
  <div class="common-layout">
    <el-container>
      <el-aside width="241px">
        <Search :filter="filter" class="search"></Search>
        <Aside :menus="$store.menus" style="height: 95vh">
        </Aside>
      </el-aside>
      <el-container>
        <el-header class="hr-header">
          <TableHead :tableTitle="$store.tableTitle" :tableOperations="$store.tableOperations" :saveData="saveData"
            :addTitle="$store.addTitle" :dataitem="$store.dataitem" />
          <Search :filter="filter" class="search"></Search>
          <Edit class="edit"></Edit>
          <el-button @click="controlShow">
            过滤
            <Filter :data="$store.data" v-show="$store.show" class="filter">
            </Filter>
          </el-button>
        </el-header>
        <el-main>
          <div class="table">
            <MainTable :tableData="$store.tableData" :xmlData="newXmlData" @cell-click="changeInfo">
            </MainTable>
            <MessageBox v-show="false"></MessageBox>
            <Notification v-show="false"></Notification>
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
import Edit from '@/components/edit/Edit.vue'
import Aside from '@/components/aside/Aside.vue'
import MainTable from '@/components/MainTable.vue'
import ColumnFilter from '@/components/columnFilter/ColumnFilter.vue'
import Pagination from '@/components/pagination/Pagination.vue'
import Filter from '@/components/filter/Filter.vue'
import MessageBox from '@/components/feedback/MessageBox.vue'
import Notification from '@/components/feedback/Notification.vue'
import { useInfoStore } from '@/stores/archivesInfo'

const $store = useInfoStore()
// 全局事件总线
const mitt = getCurrentInstance().appContext.config.globalProperties.$bus
//侧边栏
$store.asideData()

//过滤器
const controlShow = () => {
  $store.show = !$store.show
}
const res = $store.requestRes($store.data)
mitt.on('search', res)

//表格数据
$store.initTableData()

//新增档案
$store.addConfig()

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

//编辑表单数据
$store.editInfo()
provide('userData', $store.userData)

//消息弹出框
const changeInfo = (row, column) => {
  $store.changeMessage(row, column)
}

//消息提示
$store.changeSaveValue()
$store.changeWarnValue()
$store.changeImportValue()
</script>

<style lang="scss" scoped>
.search {
  flex: 0 0 auto;
  /* 不伸缩、不收缩，固定高度 */
  float: right;
}

.filter {
  color: purple;
  height:150px;
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

.hr-header .edit {
  display: flex;
}
</style>
