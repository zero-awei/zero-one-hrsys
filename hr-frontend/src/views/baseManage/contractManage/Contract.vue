<template>
  <el-container>
    <el-aside width="200px">
      <Aside :menus="menus" style="height: calc(100%-60px)"></Aside>
    </el-aside>
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
      <el-main>
        <MainTable
          :tableData="tableData"
          :xmlData="newXmlData"
          class="maintable"
        ></MainTable>
      </el-main>
      <el-footer>
        <div class="footer">
          <ColumnFilter :xmlData="xmlData" :parentMethod="getNewXmlData" />
          <Pagination :pageSizes="pageSizes" :total="tableData"></Pagination>
        </div>
      </el-footer>
    </el-container>
  </el-container>
</template>

<script setup>
import Aside from '@/components/aside/Aside.vue'
import TableHead from '@/components/table/head/TableHead.vue'
import MainTable from '@/components/MainTable.vue'
import Search from '@/components/SearchBox.vue'
import Pagination from '@/components/pagination/Pagination.vue'
import ColumnFilter from '@/components/columnFilter/ColumnFilter.vue'

const menus = reactive([
  {
    path: '/sample',
    text: '空白页',
    icon: 'user'
  },
  {
    path: '/sample/excel',
    text: 'Excel演示',
    icon: 'user'
  },
  {
    path: '/sample/print',
    text: '打印演示',
    icon: 'user'
  },
  {
    path: '/sample/edit',
    text: '信息编辑页',
    icon: 'user'
  },
  {
    path: '/sample/sass',
    text: 'sass演示',
    icon: 'user'
  },
  {
    path: '/sample/communication',
    text: '兄弟组件通信',
    icon: 'user'
  },
  {
    path: '/sample/pagination',
    text: '分页',
    icon: 'user'
  },
  {
    path: '/sample/sass',
    text: 'sass演示',
    icon: 'user'
  },
  {
    path: '/sample/communication',
    text: '兄弟组件通信',
    icon: 'user'
  },
  {
    path: '/sample/pagination',
    text: '分页',
    icon: 'user'
  },
  {
    path: '/sample/sass',
    text: 'sass演示',
    icon: 'user'
  },
  {
    path: '/sample/communication',
    text: '兄弟组件通信',
    icon: 'user'
  },
  {
    path: '/sample/pagination',
    text: '分页',
    icon: 'user'
  },
  {
    path: '/sample/sass',
    text: 'sass演示',
    icon: 'user'
  },
  {
    path: '/sample/communication',
    text: '兄弟组件通信',
    icon: 'user'
  },
  {
    path: '/sample/pagination',
    text: '分页',
    icon: 'user'
  }
])

// 定义表单数据
const xmlData = [
  { id: 1, name: '员工编号', prop: 'id' },
  { id: 2, name: '员工姓名', prop: 'name' },
  { id: 3, name: '员工所属单位', prop: 'belong' },
  { id: 4, name: '员工状态', prop: 'state' },
  { id: 5, name: '到本单位时间', prop: 'entryTime' },
  { id: 6, name: '合同编号', prop: 'contractNo' },
  { id: 7, name: '合同签订单位', prop: 'signingUnit' },
  { id: 8, name: '合同类别', prop: 'contractCategory' },
  { id: 9, name: '合同类型', prop: 'contractType' },
  { id: 10, name: '起始时间', prop: 'startTime' },
  { id: 11, name: '结束时间', prop: 'endTime' },
  { id: 12, name: '合同状态', prop: 'contractState' },
  { id: 13, name: '合同剩余天数', prop: 'remainingDays' },
  { id: 14, name: '试用到期天数', prop: 'expirationTime' }
]

function getNewXmlData(checkStatus) {
  newXmlData.value = xmlData.filter((item) => {
    return checkStatus.value.includes(item.name)
  })
}
const newXmlData = ref([])
newXmlData.value = [...xmlData]

const pageSizes = [10, 20, 30]
const filter = (val) => {
  console.log(`output->`, val)
}
//表格表名
const tableTitle = ref('合同信息')
//新增表单的表名
const addTitle = ref('合同信息')
//功能按键需求配置
const tableOperations = reactive([
  {
    name: '搜索'
  },
  {
    name: '新增'
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

<style lang="scss" scoped>
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
  .maintable {
    position: absolute;
    text-align: center;
  }
}
.pagination {
  flex: 0 0 auto; /* 不伸缩、不收缩，固定高度 */
}

.footer {
  display: flex;
  justify-content: space-between;
  align-items: center;
}
</style>
