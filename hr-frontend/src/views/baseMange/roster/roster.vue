<template>
    <el-container>
      <el-header>
        <TableHead
          :tableTitle="tableTitle"
          :addTitle="addTitle"
          :tableOperations="tableOperations"
          :addData="addData"
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
  import MainTable from '@/components/MainTable.vue'
  import Search from '@/components/SearchBox.vue'
  import Pagination from '@/components/pagination/Pagination.vue'
  import { reactive, ref } from 'vue'
  import 'element-plus/dist/index.css'
  interface User {
    //自定义数据
    id: number
    name: string
    department: string
    position: string
    job: string
    certificateId: number
    phoneNumber: number
    state: string
    sex:string
    nation:string
  }
  // 定义表单数据
  const xmlData = [
  { id: 1, name: '工作单位', prop: 'workUnit' },
  { id: 2, name: '部门', prop: 'department' },
    { id: 3, name: '员工编号', prop: 'id' },
    { id:4, name: '员工姓名', prop: 'name' },
    { id: 5, name: '性别', prop: 'sex' },
    { id: 6, name: '民族', prop: 'nation' },
    { id: 7, name: '出生日期', prop: 'certificateId' },
    { id: 8, name: '年龄', prop: 'age' },
    { id: 9, name: '政治面貌', prop: 'age' },
    { id: 10, name: '最高学历毕业院校', prop: 'age' },
    { id: 11, name: '最高学历', prop: 'age' },
    { id: 12, name: '最高学历学校类别', prop: 'organization' },
    { id: 13, name: '最高学历学习形式', prop: 'position' },
    { id: 14, name: '最高学历毕业时间', prop: 'job' },
    { id: 15, name: '最高学历所学专业', prop: 'certificateId' },
    { id: 16, name: '参加工作时间', prop: 'phoneNumber' },
    { id: 11, name: '员工状态', prop: 'state' }
  ]
  // 注入表格数据
  const tableData = [
    {
      id: 10001,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10002,
      name: '甄子丹',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10003,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10004,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10005,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10006,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10007,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10008,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10009,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10010,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10001,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10002,
      name: '甄子丹',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10003,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10004,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10005,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10006,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10007,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10008,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10009,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10010,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10001,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10002,
      name: '甄子丹',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10003,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10004,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10005,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10006,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10007,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10008,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10009,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10010,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10001,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10002,
      name: '甄子丹',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10003,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10004,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10005,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10006,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10007,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10008,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10009,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10010,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10001,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10002,
      name: '甄子丹',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10003,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10004,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10005,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10006,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10007,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10008,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10009,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    },
    {
      id: 10010,
      name: '彭于晏',
      age: 26,
      organization: '集团总部',
      department: '企业部门',
      position: '总规划师',
      job: '培训管理',
      certificateId: 140821199103011618,
      phoneNumber: 15035052120,
      state: '在职'
    }
  ]
  const pageSizes = [10, 20, 30]
  const filter = (val) => {
    console.log(`output->`, val)
  }
  //表格表名
  const tableTitle = ref('花名册')
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
  </script>
  
  <style scoped lang="less">
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