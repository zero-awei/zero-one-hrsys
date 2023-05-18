<template>
  <button @click="myEmit">表格某一列</button>
  <br/>
  <el-button text @click="showMsg()">操作</el-button>
</template>

<script setup>
let messageInfo = ref('确定删除吗？')
let message = ref('保存成功')
let messageError = ref('校验失败')

//接受父组件传过来的值
const testMessage = defineProps({
  messageInfo: {
    type: String, //类型字符串
    default: '' //如果没有传递参数,默认值是这个
  },
  messageError: {
    type: String, 
    default: '' 
  }
})

//子组件调用父组件的方法
const myEmit = defineEmits(['onchangeMessage'])
myEmit('onchangeMessage', 'changeMessage')

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
        message: testMessage.messageInfo
      })
    })
    .catch(() => {
      ElMessage({
        type: 'info',
        message: testMessage.messageError
      })
    })
}
</script>
