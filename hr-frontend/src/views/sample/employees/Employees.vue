<template>
  <el-table :data="rows" stripe>
    <el-table-column prop="Index" label="编号" min-width="30%" />
    <el-table-column prop="Name" label="名称" min-width="70%" />
  </el-table>
  <el-button type="primary" @click="exportFile">导出</el-button>
</template>

<script setup>
import { ref, onMounted } from 'vue'
import { read, utils, writeFileXLSX } from 'xlsx'
const rows = ref([])
/**
 * 挂载的时候加载数据
 */
onMounted(async () => {
  /* Download from https://sheetjs.com/pres.numbers */
  const f = await fetch('https://sheetjs.com/pres.numbers')
  const ab = await f.arrayBuffer()
  /* parse workbook */
  const wb = read(ab)
  /* update data */
  rows.value = utils.sheet_to_json(wb.Sheets[wb.SheetNames[0]])
})

/* get state data and export to XLSX */
function exportFile() {
  const ws = utils.json_to_sheet(rows.value)
  const wb = utils.book_new()
  utils.book_append_sheet(wb, ws, 'Data')
  writeFileXLSX(wb, 'SheetJSVueAoO.xlsx')
}
</script>

<style scoped>
.el-table {
  width: 100%;
}
.el-button {
  margin-top: 5px;
}
</style>
