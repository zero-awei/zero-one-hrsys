<template>
  <el-button text @click="showMsg()">操作</el-button>
  <button @click="changeContent">警告内容</button>
</template>

<script setup>
let messageInfo = ref('确定删除吗？')
let message = ref('保存成功')
let messageError = ref('校验失败')

const showMsg = () => {
  ElMessageBox.confirm(messageInfo.value, '警告', {
    confirmButtonText: '确定',
    cancelButtonText: '取消',
    type: 'warning'
  })
    .then(() => {
      ElMessage({
        title: '成功',
        type: 'success',
        message: message.value
      })
    })
    .catch(() => {
      ElMessage({
        type: 'info',
        message: messageError.value
      })
    })
}
const changeContent=()=>{
  messageInfo.value='确定修改吗?'
  message='某某操作成功'
  messageError='值规则校验异常'
}
</script>
