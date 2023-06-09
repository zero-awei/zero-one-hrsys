<template>
  <el-container>
    <el-aside width="200px">
      <Aside :menus="menus" style="height: calc(100%-60px)"></Aside>
    </el-aside>
    <el-container>
      <el-header>
        <TableHead
          :filter="filter"
          :tableTitle="$store.tableTitle"
          :tableOperations="$store.tableOperations"
          :saveData="saveData"
          :addTitle="$store.addTitle"
          :dataitem="$store.dataitem"
          :deleteData="deleteData"
        />
      </el-header>
      <el-main>
        <MainTable
          :tableData="$store.tableData"
          :xmlData="newXmlData"
          :isSelection="true"
          class="maintable"
        ></MainTable>
      </el-main>
      <el-footer>
        <div class="footer">
          <ColumnFilter :xmlData="$store.xmlData" :parentMethod="getNewXmlData" />
          <Pagination :total="$store.total"></Pagination>
        </div>
      </el-footer>
    </el-container>
  </el-container>
</template>

<script setup>
import Aside from '@/components/aside/Aside.vue'
import TableHead from '@/components/table/head/TableHead.vue'
import MainTable from '@/components/MainTable.vue'
import Search from '@/components/SearchBox.vue'
import ColumnFilter from '@/components/columnFilter/ColumnFilter.vue'
import Pagination from '@/components/pagination/Pagination.vue'

import { useContractStore } from '@/stores/contract'
import { getCurrentInstance, onMounted, onBeforeMount } from 'vue'

const $store = useContractStore()
const { $bus } = getCurrentInstance().appContext.config.globalProperties
let pageSize = 10
let currentPage = 1
onBeforeMount(() => {
  $store.initTableData(pageSize,currentPage)
})
onMounted(()=>{
  $bus.on('getPageSize',(data)=>{
    pageSize = data.value
    $store.initTableData(pageSize,currentPage)
  })
  $bus.on('getCurrentPage',(data)=>{
    currentPage = data.value
    $store.initTableData(pageSize,currentPage)
  })
})



function getNewXmlData(checkStatus) {
  newXmlData.value = $store.xmlData.filter((item) => {
    return checkStatus.value.includes(item.name)
  })
}
const newXmlData = ref([])
newXmlData.value = [...$store.xmlData]

const filter = (val) => {
  console.log(`output->`, val)
}


const menus = reactive([
  {
    path: '/sample',
    text: '空白页',
    icon: 'user'
  },
  {
    path: '/sample/excel',
    text: 'Excel演示',
    icon: 'user'
  },
  {
    path: '/sample/print',
    text: '打印演示',
    icon: 'user'
  },
  {
    path: '/sample/edit',
    text: '信息编辑页',
    icon: 'user'
  },
  {
    path: '/sample/sass',
    text: 'sass演示',
    icon: 'user'
  },
  {
    path: '/sample/communication',
    text: '兄弟组件通信',
    icon: 'user'
  },
  {
    path: '/sample/pagination',
    text: '分页',
    icon: 'user'
  },
  {
    path: '/sample/sass',
    text: 'sass演示',
    icon: 'user'
  },
  {
    path: '/sample/communication',
    text: '兄弟组件通信',
    icon: 'user'
  },
  {
    path: '/sample/pagination',
    text: '分页',
    icon: 'user'
  },
  {
    path: '/sample/sass',
    text: 'sass演示',
    icon: 'user'
  },
  {
    path: '/sample/communication',
    text: '兄弟组件通信',
    icon: 'user'
  },
  {
    path: '/sample/pagination',
    text: '分页',
    icon: 'user'
  },
  {
    path: '/sample/sass',
    text: 'sass演示',
    icon: 'user'
  },
  {
    path: '/sample/communication',
    text: '兄弟组件通信',
    icon: 'user'
  },
  {
    path: '/sample/pagination',
    text: '分页',
    icon: 'user'
  }
])
</script>

<style lang="scss" scoped>
.search {
  flex: 0 0 auto; /* 不伸缩、不收缩，固定高度 */
  float: right;
}
.form {
  flex: 1 0 auto; /* 可以伸缩、不收缩 */
  position: relative;
  display: flex;
  justify-content: center; /* 让内部元素水平居中 */
  align-items: center; /* 让内部元素垂直居中 */
  .maintable {
    position: absolute;
    text-align: center;
  }
}
.pagination {
  flex: 0 0 auto; /* 不伸缩、不收缩，固定高度 */
}

.footer {
  display: flex;
  justify-content: space-between;
  align-items: center;
}
</style>
