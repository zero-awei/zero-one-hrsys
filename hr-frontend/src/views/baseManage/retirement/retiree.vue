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
  name: string
  age: number
  organization: string
  department: string
  position: string
  job: string
  certificateId: number
  phoneNumber: number
  state: string
}
// 定义表单数据
const xmlData = [
  { id: 1, name: '员工编号', prop: 'id' },
  { id: 2, name: '员工姓名', prop: 'name' },
  { id: 3, name: '性别', prop: 'sex' },
  { id: 4, name: '年龄', prop: 'age' },
  { id: 5, name: '通讯地址', prop: 'address' },
  { id: 6, name: '退休地', prop: 'retirementPlace' },
  { id: 7, name: '家庭联系人', prop: 'familyContact' },
  { id: 8, name: '家庭联系人电话', prop: 'familyContactNumber' },
  { id: 9, name: '组织', prop: 'organization' },
  { id: 10, name: '部门', prop: 'department' },
  { id: 11, name: '职级', prop: 'rank' },
  { id: 12, name: '退休前职务', prop: 'position' },
  { id: 13, name: '退休前岗位', prop: 'job' },
  { id: 14, name: '退休时间', prop: 'retirementTime' },
  { id: 14, name: '实际退休时间', prop: 'actualRetirementtime' },
  { id: 14, name: '手机号码', prop: 'phoneNumber' },
  { id: 14, name: '审批的养老金额', prop: 'pension' },
]
// 注入表格数据
const tableData: User[] = [
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
const tableTitle = ref('离(退)休人员')
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