<template>
  <el-container>
    <el-header>
      <TableHead
        :tableTitle="tableTitle"
        :addTitle="addTitle"
        :tableOperations="tableOperations"
        :dataitem="dataitem"
        :saveData="saveData"
      >
        <Search :filter="filter" class="search"></Search>
      </TableHead>
    </el-header>
    <el-main
      ><MainTable
        :tableData="tableData"
        :xmlData="xmlData"
        class="maintable"
      ></MainTable
    ></el-main>
    <el-footer
      ><Pagination :pageSizes="pageSizes" :total="tableData.length"></Pagination
    ></el-footer>
  </el-container>
</template>
  
  <script lang="ts" setup>
import TableHead from '@/components/table/head/TableHead.vue'
import MainTable from '../../../components/MainTable.vue'
import Search from '@/components/SearchBox.vue'
import Pagination from '@/components/pagination/Pagination.vue'
import { reactive, ref } from 'vue'
import 'element-plus/dist/index.css'
interface User {
  //自定义数据
  id: number
  category: string
  amount: number
  number: number
  time: string
  standard: string
}
// 定义表单数据
const xmlData = [
  { id: 1, name: '费用类别', prop: 'category' },
  { id: 2, name: '费用金额', prop: 'amount' },
  { id: 3, name: '发放人数', prop: 'number' },
  { id: 4, name: '发放时间', prop: 'time' },
  { id: 5, name: '费用标准', prop: 'standard' }
]
// 注入表格数据
const tableData: User[] = [
  {
    id: 200,
    category: '补贴',
    amount: 3000,
    number: 200,
    time: '2002-5-20',
    standard: '第二标准'
  }
]
const pageSizes = [10, 20, 30]
const filter = (val) => {
  console.log(`output->`, val)
}
//表格表名
const tableTitle = ref('费用台账')
//新增表单的表名
const addTitle = ref('人员列表编辑')
//功能按键需求配置
const tableOperations = reactive([
  {
    name: '搜索'
  },
  {
    name: '新增'
  },
  {
    name: '删除'
  }
])
//新增表单所需栏目配置
const dataitem = reactive([
  {
    label: '员工姓名',
    name: 'name',
    type: String
  },
  {
    label: '员工编号',
    name: 'ID',
    type: Array,
    //如果是选项请配置以下属性
    options: [
      {
        id: 1,
        optionData: '111'
      },
      {
        id: 2,
        optionData: '222'
      }
    ]
  },
  {
    label: '备注',
    name: 'remark',
    type: 'Text'
  }
])

const saveData = (val) => {
  //写保存数据的逻辑
}
</script>
  
  <style scoped lang="scss">
.container {
  display: flex; /* 使用一个 flex 容器实现布局 */
  flex-direction: column; /* 竖直方向排列 */
  height: 100vh; /* 设置高度为视口高度，使布局充满整个屏幕 */
}
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
  text-align: center;
  .maintable {
    position: absolute;
  }
}
.pagination {
  flex: 0 0 auto; /* 不伸缩、不收缩，固定高度 */
}
</style>