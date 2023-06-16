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
      <el-button>启用</el-button>
      <el-button>禁用</el-button>
    </div>
    <div class="table">
      <MainTable
        :xmlData="newXmlData"
        :tableData="$store.tableData"
        :isSelection="true"
      />
    </div>
    <div class="footer">
      <ColumnFilter :xmlData="$store.xmlData" :parentMethod="getNewXmlData" />
      <Pagination :total="$store.total" />
    </div>
  </div>
</template>

<script lang="ts" setup>
import TableHead from '@/components/table/head/TableHead.vue'
import MainTable from '@/components/MainTable.vue'
import { getCurrentInstance, onBeforeMount, onMounted, ref } from 'vue'
import { ElMessage } from 'element-plus'
import { userManageStore } from '@/stores/userManage'
import { addUser, deleteUser } from '@/apis/sysManage/userManage'
const $store = userManageStore()

//处理页码
const { $bus } = getCurrentInstance().appContext.config.globalProperties
let pageSize = 10
let currentPage = 1
onBeforeMount(() => {
  $store.initTableData(pageSize, currentPage)
  $store.initDataItem()
})

onMounted(() => {
  $bus.on('getPageSize', (data) => {
    pageSize = data.value
    $store.initTableData(pageSize, currentPage)
  })
  $bus.on('getCurrentPage', (data) => {
    currentPage = data.value
    $store.initTableData(pageSize, currentPage)
  })
})

//将新增的数据保存
const addData = (val) => {
  addUser(
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
    deleteUser(
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

//选择列逻辑
function getNewXmlData(checkStatus) {
  newXmlData.value = $store.xmlData.filter((item) => {
    return checkStatus.value.includes(item.name)
  })
}
const newXmlData = ref([])
newXmlData.value = [...$store.xmlData]
</script>

<style>
.footer {
  display: flex;
  justify-content: space-between;
  align-items: center;
}
</style>
