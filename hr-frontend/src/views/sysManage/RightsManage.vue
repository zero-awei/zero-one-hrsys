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

const deleteData = (val) => {
  const dataArr = []
  for (let index of val.keys()) {
    dataArr.push(val[index].id)
  }
  // console.log(data)
  for (let i = 0; i < dataArr.length; i++) {
    deleteRights(
      {
        id: dataArr[i]
      },
      () => {
        $store.initTableData()
        ElMessage.success('删除成功')
      },
      () => {
        ElMessage.error('删除失败')
      }
    )
  }
}
</script>

<style></style>
