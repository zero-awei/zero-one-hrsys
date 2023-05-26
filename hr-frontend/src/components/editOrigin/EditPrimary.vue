<template>
  <div class="input-primary">
    <slot class="t1" name="t1"></slot>
    <span>{{ label1 }}</span>
    <el-input class="" v-model="input" placeholder="" />
  </div>
</template>

<script setup>
const input = ref('')
const props = defineProps({
  label1: {
    type: String,
    default: 't1'
  }
})
</script>

<style lang="scss" scoped>
.input-primary {
  height: 33px;
  width: 430px;
  display: flex;
  justify-content: flex-end;
  span {
    line-height: 33px;
    margin-right: 10px;
  }
  .el-input {
    width: 300px;
  }
}
</style>
