<template>
  <el-container>
   <el-aside width="200px">
       <Aside :menus="$store.menus" style="height: calc(100%-60px)"></Aside>
   </el-aside>
   <el-container>
     <el-header>
       <TableHead
       :tableTitle="$store.tableTitle"
       :addTitle="$store.addTitle"
       :saveData="saveData" 
       :tableOperations="$store.tableOperations"
       :dataitem="$store.dataitem">
       </TableHead>
     </el-header>
     <el-main>
       <MainTable
       :tableData="$store.tableData"
       :xmlData="newXmlData"
       class="maintable"
     ></MainTable>
     </el-main>
     <el-footer class="footer">
       <ColumnFilter :xmlData="$store.xmlData" :parentMethod="getNewXmlData"/>
       <Pagination :pageSizes="$store.pageSizes" :total="$store.total"></Pagination>
     </el-footer>
   </el-container>
 </el-container>
</template>

<script  setup>
import Aside from '@/components/aside/Aside.vue'
import TableHead from '@/components/table/head/TableHead.vue'
import MainTable from '@/components/MainTable.vue'
import Pagination from '@/components/pagination/Pagination.vue'
import ColumnFilter from '@/components/columnFilter/ColumnFilter.vue'
import {addOrgInfo} from '@/apis/orgManger/orgInfo/index'
import { orgInfoStore } from '@/stores/orgInfo'
import { getCurrentInstance, onMounted } from 'vue'
import { useRouter } from 'vue-router'
import { ElMessage } from 'element-plus'
const $store = orgInfoStore()
const $router = useRouter()
$store.initTableData()


const saveData = (val)=>{
  console.log(val);
  $store.addData(val);
  addOrgInfo(val,
  ()=>{
    ElMessage.success('增加成功')
  },
  ()=>{
    ElMessage.success('增加失败，请重试')
  });
}

const { $bus } = getCurrentInstance().appContext.config.globalProperties
onMounted(() => {
    // 监听多选数据
  $bus.on('getRowsData', (data) => {
    let ids = data.value.map((item) => item.id)
    console.log(ids)
  })
    // 监听单行数据
  $bus.on('getSingleRowData', (data) => {
    console.log(data)
    // $router.push('/sample/employees')
  })
})
function getNewXmlData(checkStatus) {
  newXmlData.value = $store.xmlData.filter((item) => {
    return checkStatus.value.includes(item.name)
  })
}
const newXmlData = ref([])
newXmlData.value = [...$store.xmlData]

</script>

<style lang='scss' scoped>


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

.footer{
  z-index: 1;
  display: flex;
  justify-content: space-between;
  align-items: center;
}
</style>