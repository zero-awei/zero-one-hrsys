<template>
  <div class="hr-maintable">
    <el-table
      class-name="hr-maintable__form"
      ref="multipleTableRef"
      max-height="calc(95vh - 40px)"
      :data="tableData"
      style="width: 100%"
      @selection-change="handleSelectionChange"
      @row-dblclick="handleClick"
      :default-sort="{ prop: 'id', order: 'ascending' }"
    >
      <el-table-column type="selection" />
      <el-table-column
        class-name="hr-maintable__form--cell"
        v-for="item in xmlData"
        :key="item.id"
        :label="item.name"
        :prop="item.prop"
        width="150"
        sortable
        @dbclick=""
      />
    </el-table>
  </div>
</template>

<script lang="ts" setup>
import { PropType, ref } from 'vue'
import { ElTable } from 'element-plus'
// 表单实体
const multipleTableRef = ref<InstanceType<typeof ElTable>>()
//多选获得数据存取变量
const multipleSelection = ref<User[]>([])

const props = defineProps({
  xmlData: {
    type: Array as PropType<TableCell[]>,
    default: () => []
  },
  tableData: {
    type: Array as PropType<User[]>
  }
})
// 处理多选事件
const handleSelectionChange = (val) => {
  multipleSelection.value = val
  // 拿到数据
  // console.log(multipleSelection.value)
}
// 双击事件预留函数
const handleClick = (val) => {
  // 双击可以拿到改行的val值
  //console.log(val)
}
//用户数据类型定义
interface User {
  //自定义数据
  id: number
  name?: string
  age?: number
  organization?: string
  department?: string
  position?: string
  job?: string
  certificateId?: number
  phoneNumber?: number
  state?: string
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
      max-height: 30px;
      cursor: pointer;
    }
  }
}
.el-table__header {
  height: 58px;
}
.el-table__header-wrapper thead {
  font-weight: bolder;
  color: #304265;
  font-size: 16px;
  font-weight: bold;
}
</style>
