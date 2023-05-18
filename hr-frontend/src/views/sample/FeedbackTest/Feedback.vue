<template>
  <div>
    <el-row>
      <el-button @click="changeMesage">点击表格某一列--决定弹出的内容</el-button>
    </el-row>
    <Notification
      @onChangeMessage="changeMessage"
      :messageInfo="message"
      :messageError="error"
      :messageWarn="warn"
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

const message = ref('成功')
const error = ref('出错')
const warn=ref('警告')
const changeMesage = () => {
  message.value = 'XXXX保存成功'
  error.value = '值规则校验失败了'
  warn.value="警告"
}
</script>

<style lang="scss" scoped></style>
