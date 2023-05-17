<template>
  <el-button text @click="open">触发字段名</el-button>
</template>

<script  setup>
import { ElMessage, ElMessageBox } from 'element-plus'

const open = () => {
  ElMessageBox.confirm(
    '确认离职吗?',
    '警告',
    {
      confirmButtonText: '确定',
      cancelButtonText: '取消',
      type: 'warning',
    }
  )
    .then(() => {
      ElMessage({
        title：'成功'
        type: 'success',
        message: '离职成功',
      })
    })
    .catch(() => {
      })
    })
}
</script>
