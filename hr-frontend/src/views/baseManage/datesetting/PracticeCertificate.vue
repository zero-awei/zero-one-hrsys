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
  licensingName: string
  rank: string
  licensing: string
  professional: string
}
// 定义表单数据
const xmlData = [
  { id: 1, name: '执业资格名称', prop: 'licensingName' },
  { id: 2, name: '级别', prop: 'rank' },
  { id: 3, name: '执业资格', prop: 'licensing' },
  { id: 4, name: '专业', prop: 'professional' }
]
// 注入表格数据
const tableData: User[] = [
  {
    id: 200,
    licensingName: '补贴',
    rank: '大佐',
    licensing: '有',
    professional: '物联网'
  }
]
const pageSizes = [10, 20, 30]
const filter = (val) => {
  console.log(`output->`, val)
}
//表格表名
const tableTitle = ref('执业资格专业')
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