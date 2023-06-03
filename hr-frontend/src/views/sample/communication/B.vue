<template>
  <div class="hr-btn" @click="toA">B组件</div>
</template>

<script setup>
const mitt = getCurrentInstance().appContext.config.globalProperties.$bus
// 给B发消息
let val = ref('hello A')
const toA = () => {
  mitt.emit('callA', val.value)
}

// 绑定触发函数
const fn = (val) => {
  console.log(`output->B`, val)
}
mitt.on('callB', fn)
</script>

<style lang="scss" scoped>
@include block(btn) {
  width: 100px;
  // height: 20px;
  padding: 5px 10px;
  text-align: center;
  background-color: #e67e22;
}
</style>
