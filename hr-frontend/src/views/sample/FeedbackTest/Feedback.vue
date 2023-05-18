<template>
  <div>
    <el-row>
      <el-button>测试表格某一列</el-button>
    </el-row>
    <Notification
      @onChangeMessage="changeMessage"
      :messageInfo="message"
      :messageError="error"
    >
    </Notification>
    <MessageBox
      @onChangeMessage="changeMessage"
      :messageInfo="message"
      :messageError="error"
    ></MessageBox>
    <!-- 父组件传参数到子组件 -->
    <!-- 子组件调用父组件的changeMessage()方法-->
  </div>
</template>

<script setup>
import MessageBox from '@/components/feedback/MessageBox.vue'
import Notification from '@/components/feedback/Notification.vue'

const message = ref('确定吗？')
const error = ref('出错')
const changeMesage = () => {
  message.value = 'xx保存成功'
  error.value = '校验失败'
}
</script>

<style lang="scss" scoped></style>
