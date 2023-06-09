<template>
  <el-container>
    <el-header>
      <TableHead    
        :filter="filter"
        :tableTitle="$store.tableTitle"
        :tableOperations="$store.tableOperations"
        :saveData="saveData"
        :addTitle="$store.addTitle"
        :dataitem="$store.dataitem"
      />
    </el-header>
    <el-main>
      <MainTable 
        :xmlData="newXmlData" 
        :tableData="$store.tableData" 
        :isSelection="true"
      />
    </el-main>
    <el-footer>
      <div class="footer">
        <ColumnFilter :xmlData="$store.xmlData" :parentMethod="getNewXmlData" />
        <Pagination  :total="$store.total" />
      </div>
    </el-footer>
  </el-container>
</template>

<script setup>
import TableHead from '@/components/table/head/TableHead.vue'
import MainTable from '@/components/MainTable.vue'
import ColumnFilter from '@/components/columnFilter/ColumnFilter.vue'
import Pagination from '@/components/pagination/Pagination.vue'
import {addCertificateInfo} from '@/apis/certificateManage/certificateInfo/index'
import 'element-plus/dist/index.css'
import { useCertificateInfoStore } from '@/stores/certificateInfo'
import { getCurrentInstance,onMounted,onBeforeMount } from 'vue'

const $store = useCertificateInfoStore()
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

//将新增的数据保存
const saveData = (val) => {
    addCertificateInfo(
    val,
    () => {
      //$store.initTableData(pageSize,currentPage)
      ElMessage.success('添加成功')
    },
    () => {
      ElMessage.error('添加失败')
    }
  )
  //$store.addData(val)
}

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
</script>

<style lang="scss" scoped>
.footer {
  display: flex;
  justify-content: space-between;
  align-items: center;
}
</style>