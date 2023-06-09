<template>
  <div class="hr-maintable">
    <el-table
      class-name="hr-maintable__form"
      ref="multipleTableRef"
      :max-height="maxHeight ? maxHeight : 'calc(95vh - 150px)'"
      :data="tableData"
      style="width: 100%; text-align: center"
      @selection-change="handleSelectionChange"
      @row-dblclick="handleClick"
      :default-sort="{ prop: 'id', order: 'ascending' }"
      :stripe="true"
    >
      <el-table-column v-if="isSelection" type="selection" />
      <el-table-column
        class-name="hr-maintable__form--cell"
        v-for="item in xmlData"
        :key="item.id"
        :label="item.name"
        :prop="item.prop"
        min-width="150"
        sortable
      />
    </el-table>
  </div>
</template>

<script lang="ts" setup>
import { PropType, ref, getCurrentInstance } from 'vue'
import { ElTable } from 'element-plus'
// 表单实体
const multipleTableRef = ref<InstanceType<typeof ElTable>>()
//多选获得数据存取变量
const multipleSelection = ref<User[]>([])
// 获取到 全局事件总线
const { $bus } = getCurrentInstance().appContext.config.globalProperties

const props = defineProps({
  xmlData: {
    type: Array as PropType<TableCell[]>,
    default: () => []
  },
  tableData: {
    type: Array as PropType<User[]>
  },
  maxHeight: {
    type: String || undefined
  },
  isSelection: {
    type: Boolean
  }
})
// 处理多选事件
const handleSelectionChange = (val) => {
  multipleSelection.value = val
  // 将拿到的数据 放入全局事件总线
  $bus.emit('getRowsData', multipleSelection)
}
// 双击事件预留函数
const handleClick = (val) => {
  // 将双击拿到的单行数据放入全局事件总线
  $bus.emit('getSingleRowData', val)
}
// 以下为 需要监听表格数据的兄弟组件拿到数据的方法demo
// import { getCurrentInstance, onMounted } from 'vue'
// const { $bus } = getCurrentInstance().appContext.config.globalProperties
// onMounted(() => {
//     监听多选数据
//   $bus.on('getRowsData', (data) => {
//     let ids = data.value.map((item) => item.id)
//     console.log(ids)
//   })
//     监听单行数据
//   $bus.on('getSingleRowData', (data) => {
//     console.log(data.id)
//   })
// })
//用户数据类型定义
interface User {
  //自定义数据
  id?: number
  name?: string
  age?: number
  organization?: string
  department?: string
  position?: string
  job?: string
  certificateId?: number
  phoneNumber?: number
  state?: string
  sex?: string
  address?: string
  retirePlace?: string
  familyContact?: string
  familyContactNumber?: string
  level?: string
  preRetirePosition?: string
  preRetireJob?: string
  retireTime?: string
  realRetireTime?: string
  money?: number
}
//表单数据定义
interface TableCell {
  id: number | string
  name: string
  prop: string
}
</script>

<style lang="scss" scoped>
@include block(maintable) {
  @include element(form) {
    background-color: white;
    @include modifier(cell) {
      max-height: 48px;
      cursor: pointer;
    }
    :deep(.el-scrollbar__view) {
      display: block !important;
    }
  }
}
:deep(.el-table__header) {
  height: 58px;
}
:deep(.el-table .el-table__cell) {
  height: 48px !important;
}
:deep(.el-table__header-wrapper thead) {
  font-weight: bolder;
  color: #304265;
  font-size: 16px;
  font-weight: bold;
}
</style>
