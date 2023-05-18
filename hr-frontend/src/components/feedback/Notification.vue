<template>
  <button @click="myEmit">调用父组件方法</button>
  <br/>
  <el-button plain @click="showSuccess">成功</el-button>
  <br/>
  <el-button plain @click="showWarn">警告</el-button>
  <br/>
  <el-button plain @click="showError">错误</el-button>
  <br/>
</template>

<script setup>
//接受父组件传过来的值
const testMessage = defineProps({
	 messageInfo:{
		type:String,//类型字符串
		default:''//如果没有传递参数,默认值是这个
	},
  messageError: {
    type: String, 
    default: '' 
  },
  messageWarn: {
    type: String, 
    default: '' 
  },
})

// 子组件调用父组件的方法
const myEmit=defineEmits(['onchangeMessage'])
myEmit("onchangeMessage","changeMessage",)

const showSuccess = () => {
  ElNotification({
    title: '成功',
    message: testMessage.messageInfo,
    type: 'success',
    position: 'top-right',
  })
}

const showWarn = () => {
  ElNotification({
    title: '警告',
    message: testMessage.messageWarn,
    type: 'warning',
    position: 'top-right',
  })
}

const showError = () => {
  ElNotification({
    title: '错误',
    message: testMessage.messageInfo,
    type: 'error',
    position: 'top-right',
  })
}
</script>
<style scoped>
</style>