<template>
  <el-button plain @click="open1">成功</el-button>
  <el-button plain @click="open2">警告</el-button>
  <el-button plain @click="open3">错误</el-button>
</template>

<script setup>
import { ElNotification } from 'element-plus'

const open1 = () => {
  ElNotification({
    title: '成功',
    message: 'success message',
    type: 'success'
  })
}

const open2 = () => {
  ElNotification({
    title: '警告',
    message: 'warning message',
    type: 'warning'
  })
}

const open3 = () => {
  ElNotification({
    title: '错误',
    message: 'error message',
    type: 'error'
  })
}
</script>
