<template>
  <div class="hr-maintable">
    <el-table
      class-name="hr-maintable__form"
      ref="multipleTableRef"
      max-height="calc(95vh - 40px)"
      :data="tableData"
      style="width: 100%"
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
      />
    </el-table>
  </div>
</template>

<script lang="ts" setup>
import { PropType } from 'vue'
const props = defineProps({
  xmlData: {
    type: Array as PropType<TableCell[]>,
    default: () => []
  },
  tableData: {
    type: Array as PropType<User[]>
  }
})

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

<style lang="scss">
@include block(maintable) {
  @include element(form) {
    background-color: white;
    @include modifier(cell) {
      max-height: 30px;
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
