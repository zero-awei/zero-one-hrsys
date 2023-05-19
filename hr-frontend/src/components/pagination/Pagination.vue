<template>
  <div style="display: inline-block;">
    <el-icon>
      <icon-operation />
    </el-icon>
    <el-dropdown trigger="click" placement="top">
      <span class="el-dropdown-link">
        下拉菜单<i class="el-icon-arrow-down el-icon--right"></i>
      </span>
      <template #dropdown>
        <el-dropdown-menu>
          <el-checkbox
            v-for="items in dataList"
            :key="items.field"
            :label="items"
            style="display: block"
          >
            {{ items.label }}</el-checkbox
          >
        </el-dropdown-menu>
      </template>
    </el-dropdown>
  </div>
  <div style="float: right">
    <el-button @clike="refresh">
      <el-icon-refresh-right
        style="width: 14; height: 21; display: inline-block"
      ></el-icon-refresh-right>
    </el-button>
    <div class="block" style="display: inline-block">
      <el-pagination
        @size-change="handleSizeChange"
        @current-change="handleCurrentChange"
        v-model:currentPage="currentPage"
        :page-sizes="pageSizes"
        layout="total, sizes, prev, pager, next, jumper"
        :total="total"
      >
      </el-pagination>
    </div>
  </div>
</template>

<script>
export default {
  // 需要外部传入的参数
  props: {
    pageSizes: Array,
    total: Number
  },
  methods: {
    handleSizeChange(val) {
      console.log(`每页 ${val} 条`)
    },
    handleCurrentChange(val) {
      console.log(`当前页: ${val}`)
    },
    refresh() {}
  },
  data() {
    return {
      currentPage: 1, // 默认第一页
      checkedData: [], //多选框的值
      dataList: [
        { field: 'xxg', label: '小小怪' },
        { field: 'ddg', label: '大大怪' }
      ]
    }
  }
}
</script>

<style scoped >
.el-dropdown-link {
  cursor: pointer;
  color: #409eff;
}
.el-icon-arrow-down {
  font-size: 12px;
}
</style>
