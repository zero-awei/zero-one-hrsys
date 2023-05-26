<template>
  <!-- 信息提示组件 -->
</template>

<script setup>
// import 'element-plus/dist/index.css'
const mitt = getCurrentInstance().appContext.config.globalProperties.$bus

// 组件初次在页面渲染完毕后,触发后执行的函数
onMounted(() => {
  mitt.on('showSuccess',(messageInfo) => {
  ElNotification({
    title: '成功',
    message: messageInfo,
    type: 'success',
    position: 'top-right'
  })
})
})

onMounted(() => {
  mitt.on('showWarn',(messageInfo) => {
    ElNotification({
    title: '警告',
    message:messageInfo,
    type: 'warning',
    position: 'top-right'
  })
})
})

onMounted(() => {
  mitt.on('showError',(messageInfo) => {
    ElNotification({
    title: '错误',
    message:messageInfo,
    type: 'error',
    position: 'top-right'
  })
})
})

//在组件被销毁之前
onBeforeUnmount(() => {
  mitt.off('showSuccess','showWarn','showError')
})
</script>

<style>
.el-notification__group{
  position:static !important;
}
</style>
