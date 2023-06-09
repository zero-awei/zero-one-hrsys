<template>
  <el-container>
    <el-header>
      <TableHead :tableTitle="$store.tableTitle" :addTitle="$store.addTitle" :tableOperations="$store.tableOperations"
        :dataitem="$store.dataitem" :saveData="saveData">
        <Search :filter="filter" class="search"></Search>
      </TableHead>
      <el-button @click="controlShow">
        过滤
        <Filter :data="$store.data" v-show="$store.show" class="filter">
        </Filter>
      </el-button>
    </el-header>
    <el-main>
      <MainTable :tableData="$store.tableData" :xmlData="$store.xmlData" class="maintable"></MainTable>
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
import { useinformationReviewStore } from '@/stores/informationReview'

const $store = useinformationReviewStore() 
// 全局事件总线
const mitt = getCurrentInstance().appContext.config.globalProperties.$bus
//侧边栏
// $store.asideData()

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
</script>
  
<style scoped lang="scss">
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

.form {
  flex: 1 0 auto;
  /* 可以伸缩、不收缩 */
  position: relative;
  display: flex;
  justify-content: center;
  /* 让内部元素水平居中 */
  align-items: center;
  /* 让内部元素垂直居中 */
  text-align: center;

  .maintable {
    position: absolute;
  }
}
</style>