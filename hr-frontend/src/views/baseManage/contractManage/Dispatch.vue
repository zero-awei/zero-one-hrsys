<template>
  <div>
    <div class="header">
      <TableHead
        :tableTitle="$store.tableTitle"
        :tableOperations="$store.tableOperations"
        :saveData="saveData"
        :addTitle="$store.addTitle"
        :dataitem="$store.dataitem"
        :deleteData="deleteData"
      />
    </div>
    <div class="table">
      <MainTable :xmlData="newXmlData" :tableData="$store.tableData" />
    </div>
    <div class="footer">
      <ColumnFilter :xmlData="$store.xmlData" :parentMethod="getNewXmlData" />
      <Pagination :total="$store.total" />
    </div>
  </div>
</template>

<script setup>
import TableHead from '@/components/table/head/TableHead.vue'
import MainTable from '@/components/MainTable.vue'
import ColumnFilter from '@/components/columnFilter/ColumnFilter.vue'
import Pagination from '@/components/pagination/Pagination.vue'
import {
  addDispatch,
  deleteDispatch
} from '@/apis/contractManage/dispatch/index'
import { useDispatchStore } from '@/stores/dispatch'
import { getCurrentInstance,onMounted,onBeforeMount } from 'vue'

const $store = useDispatchStore()
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
  addDispatch(
    val,
    () => {
      $store.initTableData()
      ElMessage.success('添加成功')
    },
    () => {
      ElMessage.error('添加失败')
    }
  )
  //$store.addData(val)
}

const deleteData = (val) => {
  const data = []
  for (let index of val.keys()) {
    data.push(val[index].id)
  }
  deleteDispatch(
    {
      'id':data
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
