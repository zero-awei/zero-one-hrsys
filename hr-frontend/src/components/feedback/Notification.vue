<template>
  <el-button plain @click="showSuccess">成功</el-button>
  <el-button plain @click="showWarn">警告</el-button>
  <el-button plain @click="showError">错误</el-button>
</template>

<script setup>
let message = ref('成功')
const showSuccess = () => {
  ElNotification({
    title: '成功',
    message: 'success message',
    type: 'success',
    position: 'top-right',
  })
}

const showWarn = () => {
  ElNotification({
    title: '警告',
    message: 'warning message',
    type: 'warning',
    position: 'top-right',
  })
}

const showError = () => {
  ElNotification({
    title: '错误',
    message: 'error message',
    type: 'error',
    position: 'top-right',
  })
}
</script>
