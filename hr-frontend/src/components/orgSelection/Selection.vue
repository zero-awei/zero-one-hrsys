<template>
  <el-dialog
    v-model="dialogVisible"
    title="上级组织选择视图"
    width="90%"
    align-center
  >
    <div class="table-content">
      <Filter />
      <MainTable
        :tableData="tableData"
        :xmlData="xmlData"
        :maxHeight="maxHeight"
        :isSelection="isSelection"
      />
    </div>
    <div class="table-footer">
      <ColumnFilter :xmlData="xmlData" :parentMethod="getNewXmlData">
      </ColumnFilter>
      <Pagination />
    </div>
    <template #footer>
      <span class="dialog-footer">
        <el-button type="primary" @click="dialogVisible = false">
          确定
        </el-button>
        <el-button @click="dialogVisible = false">取消</el-button>
      </span>
    </template>
  </el-dialog>
</template>

<script lang="ts" setup>
import { ref, PropType } from 'vue'
import MainTable from '@/components/MainTable.vue'
import Pagination from '@/components/pagination/Pagination.vue'
import ColumnFilter from '@/components/columnFilter/ColumnFilter.vue'
import Filter from '@/components/filter/Filter.vue'
const props = defineProps({
  xmlData: {
    type: Array as PropType<TableCell[]>,
    default: () => []
  },
  tableData: {
    type: Array as PropType<any[]>
  },
  maxHeight: {
    type: String || undefined
  }
})
const maxHeight = 'calc(95vh - 500px)'
const isSelection = false
const dialogVisible = ref(false)
const toggleState = () => {
  dialogVisible.value = true
}
const newXmlData = ref([])
newXmlData.value = [...props.xmlData]
function getNewXmlData(checkStatus) {
  newXmlData.value = props.xmlData.filter((item) => {
    return checkStatus.value.includes(item.name)
  })
  // xmlData.value  = newXmlData
}

//表单数据定义
interface TableCell {
  id: number | string
  name: string
  prop: string
}
defineExpose({
  toggleState
})
</script>

<style lang="scss" scoped>
.dialog-footer button:first-child {
  margin-right: 10px;
}
.table-footer {
  display: flex;
  justify-content: space-between;
  margin-top: 15px;
}
</style>
