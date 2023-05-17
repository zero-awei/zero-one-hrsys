<template>
  <div class="block">
    <span class="demonstration">直接前往</span>
    <el-pagination
      @size-change="handleSizeChange"
      @current-change="handleCurrentChange"
      v-model:currentPage="currentPage3"
      :page-sizes="[20, 40, 60, 80, 100, 200, 400]"
      layout="total, sizes, prev, pager, next, jumper"
      :total="1000"
    >
    </el-pagination>
  </div>
</template>
  
  <script>
export default {
  methods: {
    handleSizeChange(val) {
      console.log(`每页 ${val} 条`)
    },
    handleCurrentChange(val) {
      console.log(`当前页: ${val}`)
    }
  },
  data() {
    return {
      currentPage1: 5,
      currentPage2: 5,
      currentPage3: 1,
      currentPage4: 4
    }
  }
}
</script>
  
  <style scoped>
</style>