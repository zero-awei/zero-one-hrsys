<template>
  <div class="Pagination">
    <div class="demo-pagination-block">
      <el-pagination
        v-model:current-page="currentPage"
        v-model:page-size="pageSize"
        :page-sizes="pageSizes"
        small="small"
        layout="total, sizes, prev, pager, next, jumper"
        :total="total"
        @size-change="handleSizeChange"
        @current-change="handleCurrentChange"
      />
    </div>
  </div>
</template>

<script setup lang="ts">
import { ref ,defineProps, defineExpose,getCurrentInstance} from 'vue'
// 获取到全局事件总线
const { $bus } = getCurrentInstance().appContext.config.globalProperties
// const handleSizeChange = (val: number) => {
//   console.log(`${val} items per page`)
// }
// const handleCurrentChange = (val: number) => {
//   console.log(`current page: ${val}`)
// }
const props = defineProps({
  currentPage: {
    type: Number,
    required: true,
  },
  pageSize: {
    type: Number,
    required: true,
  },
  total: {
    type: Number,
    required: true,
  },
  pageSizes: {
    type: Array,
    default: () => [10, 20, 30, 40],
  },

});
const currentPage = ref(props.currentPage);
const pageSize = ref(props.pageSize);
//const total = ref(props.total);
function handleSizeChange(size: number) {
  // 处理每页显示数量变化事件
  pageSize.value = size;
  $bus.emit('getPageSize', pageSize)
}
function handleCurrentChange(page: number) {
  // 处理当前页码变化事件
  currentPage.value = page;
  $bus.emit('getCurrentPage', currentPage)
}
</script>

<style lang="scss" scoped>
.Pagination {
  color: purple;
}
</style>
