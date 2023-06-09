<template>
  <!-- 消息弹出框组件 -->
</template>

<script setup>
// import 'element-plus/dist/index.css'
const mitt = getCurrentInstance().appContext.config.globalProperties.$bus

let success = ref('')
let error = ref('')
const showMsg = (message) => {
  success.value = message.messageSuccess
  error.value = message.messageError
  ElMessageBox.confirm(message.messageInfo, '警告', {
    confirmButtonText: '确定',
    cancelButtonText: '取消',
    type: 'warning'
  })
    .then(() => {
      ElMessage({
        title: '成功',
        type: 'success',
        message: success.value
      })
    })
    .catch(function () {
      ElMessage({
        title: '出错',
        type: 'info',
        message: error.value
      })
    })
}

// 组件初次在页面渲染完毕后,触发后执行的函数
onMounted(() => {
  mitt.on('changeInfo', showMsg)
})

//在组件被销毁之前
onBeforeUnmount(() => {
  mitt.off('changeInfo')
})
</script>

<style>
.el-message--success {
  position: absolute !important;
  left: 90%;
}

.el-message--info {
  position: absolute !important;
  left: 90%;
}
</style>