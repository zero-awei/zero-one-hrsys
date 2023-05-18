<template>
  <div class="hr-btn" @click="callA">B组件</div>
</template>

<script setup>

const mitt = getCurrentInstance().appContext.config.globalProperties.$bus;
const fn = (val) => {
  console.log(`output->B`,val)
}

// 绑定触发函数
mitt.on('callB', fn)

// 给A发消息
const data = ref('hello A')
const callA = () => {
  mitt.emit('callA', data.value)
}
</script>

<style lang='scss' scoped>
@include block(btn) {
  width: 100px;
  // height: 20px;
  padding: 5px 10px;
  text-align: center;
  background-color: #27ae60;
}
</style>