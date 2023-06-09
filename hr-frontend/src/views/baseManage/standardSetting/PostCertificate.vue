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
      <Pagination :pageSizes="$store.pageSizes" :total="$store.total" />
    </div>
  </div>
</template>

<script setup>
import TableHead from '@/components/table/head/TableHead.vue'
import MainTable from '@/components/MainTable.vue'
import ColumnFilter from '@/components/columnFilter/ColumnFilter.vue'
import Pagination from '@/components/pagination/Pagination.vue'
import { usePostCertificateStore } from '@/stores/postCertificate'
import { addPostCertificate,deletePostCertificate } from '@/apis/standardSetting/certificate/index'
import { ElMessage } from 'element-plus'
import { onBeforeMount } from 'vue'

const $store = usePostCertificateStore()
//页面挂载前请求数据
onBeforeMount(() => {
  $store.initTableData()
})

//将新增的数据保存
const saveData = (val) => {
  //发送POST请求以增加数据
  // addPostCertificate(
  //   {
  //     ...val
  //   },
  //   () => {
  //     $store.addData(val)
  //     ElMessage.success('添加成功')
  //   },
  //   () => {
  //     ElMessage.error('添加失败')
  //   }
  // )
  $store.addData(val)
}

//书写数据删除逻辑
const deleteData = (val) => {
  //   deletePostCertificate(
  //   {
  //     ...val
  //   },
  //   () => {
  //     $store.loadTableData()
  //   },
  //   () => {
  //     ElMessage.error('删除失败')
  //   }
  // )
  console.log(val)
}

//选择列筛选逻辑
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