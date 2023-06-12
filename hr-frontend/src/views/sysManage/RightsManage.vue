<template>
  <div>
    <div class="header">
      <TableHead
        :tableTitle="$store.title"
        :tableOperations="$store.options"
        :saveData="addData"
        :addTitle="$store.title"
        :dataitem="$store.dataitem"
        :deleteData="deleteData"
      />
    </div>
    <div class="table">
      <MainTable
        :xmlData="$store.xmlData"
        :tableData="$store.tableData"
        :isSelection="true"
      />
    </div>
  </div>
</template>

<script lang="ts" setup>
import TableHead from '@/components/table/head/TableHead.vue'
import MainTable from '@/components/MainTable.vue'
import { rightsManageStore } from '@/stores/rightsManage'
import { addRights, deleteRights } from '@/apis/sysManage/rightsManage'
import { getCurrentInstance, onBeforeMount, onMounted } from 'vue'
import { ElMessage } from 'element-plus'
const $store = rightsManageStore()
onBeforeMount(() => {
  $store.initTableData()
  $store.initDataItem()
})

//将新增的数据保存
const addData = (val) => {
  addRights(
    val,
    () => {
      $store.initTableData()
      // console.log(val)
      ElMessage.success('添加成功')
    },
    () => {
      ElMessage.error('添加失败')
    }
  )
}

const { $bus } = getCurrentInstance().appContext.config.globalProperties

// let val
// onMounted(() => {
//   $bus.on('getRowsData', (data) => {
//     let item = data.value
//     val = item[0]
//   })
// })

const deleteData = (val) => {
  deleteRights(
    val,
    //success
    () => {
      $store.initTableData()
      ElMessage.success('删除成功')
    },
    //fail
    () => {
      console.log(val)
      ElMessage.error('删除失败')
    }
  )
}
</script>

<style></style>
