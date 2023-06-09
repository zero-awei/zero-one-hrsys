<template>
  <el-container>
    <el-header>
      <TableHead    
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
        :xmlData="newXmlData" 
        :tableData="$store.tableData" 
        :isSelection="true"
      />
    </el-main>
    <el-footer>
      <div class="footer">
        <ColumnFilter :xmlData="$store.xmlData" :parentMethod="getNewXmlData" />
        <Pagination :total="$store.total" />
      </div>
    </el-footer>
  </el-container>
</template>

<script setup>
import TableHead from '@/components/table/head/TableHead.vue'
import MainTable from '../../../components/MainTable.vue'
import ColumnFilter from '@/components/columnFilter/ColumnFilter.vue'
import Pagination from '@/components/pagination/Pagination.vue'
import {addJobTitleInfo,deleteJobTitleInfo} from '@/apis/jobTitleManage/JobTitleInfo/index'
import 'element-plus/dist/index.css'
import { useJobTitleInfoStore } from '@/stores/jobTitleInfo'
import { getCurrentInstance,onMounted,onBeforeMount } from 'vue'

const $store = useJobTitleInfoStore()
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
  console.log(val)
  addJobTitleInfo(
    val,
    () => {
      $store.initTableData(pageSize,currentPage)
      ElMessage.success('添加成功')
    },
    () => {
      ElMessage.error('添加失败')
    }
  )
}
const deleteData = (val) => {
  const data = []
  for (let index of val.keys()) {
    data.push(val[index].id)
  }
  deleteJobTitleInfo(
    {
      'list_jobtitle_id':data
    },
    () => {
      $store.initTableData()
      ElMessage.success('删除成功')
    },
    () => {
      ElMessage.error('删除失败')
    }
  )
  console.log(data)
}

function getNewXmlData(checkStatus) {
  newXmlData.value = $store.xmlData.filter((item) => {
    return checkStatus.value.includes(item.name)
  })
}
const newXmlData = ref([])
newXmlData.value = [...$store.xmlData]
</script>

<style lang="scss" scoped>
.footer {
  display: flex;
  justify-content: space-between;
  align-items: center;
}
</style>