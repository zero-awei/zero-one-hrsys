<template>
  <el-container>
    <el-header
      ><TableHead
        :tableTitle="tableTitle"
        :addTitle="addTitle"
        :tableOperations="tableOperations"
        :addData="addData"
      >
        <Search :filter="filter" class="search"></Search> </TableHead
    ></el-header>
    <el-main
      ><MainTable
        :tableData="tableData"
        :xmlData="xmlData"
        class="maintable"
      ></MainTable
    ></el-main>
  </el-container>
</template>
  
<script lang="ts" setup>
import MainTable from '@/components/MainTable.vue'
import Search from '@/components/SearchBox.vue'
import 'element-plus/dist/index.css'
import { reactive, ref } from 'vue'
interface User {
  //自定义数据
  id: number
  name: string
  changeContent:string
  attachmentInformation:string
  changeType:string
  applytime:string
}
//表格表名
const tableTitle = ref('信息审核')
//新增表单的表名
const addTitle = ref('人员列表编辑')
//功能按键需求配置
const tableOperations = reactive([
  {
    name: '新增'
  },
  {
    name: '导入'
  }
])
//新增表单所需栏目配置
const addData = reactive([
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
// 定义表单数据
const xmlData = [
  { id: 1, name: '员工编号', prop: 'id' },
  { id: 2, name: '员工姓名', prop: 'name' },
  { id: 3, name: '变更内容', prop: 'changeContent' },
  { id: 4, name: '附件信息', prop: 'attachmentInformation' },
  { id: 5, name: '变更类型', prop: 'changeType' },
  { id: 6, name: '申请时间', prop: 'applytime' },
]
// 注入表格数据
const tableData = [
  {
    id: 10009,
    name: '彭于晏',
    age: 26,
    changeContent: '升值到大帅',
    attachmentInformation: '附件信息',
    changeType:'升职',
    applytime:'2003-5-20'
  },
]
const filter = (val) => {
  console.log(`output->`, val)
}
</script>
  
  <style scoped lang="less">
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
</style>