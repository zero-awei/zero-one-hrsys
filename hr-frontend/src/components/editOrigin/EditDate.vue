<template>
    <div class="demo-date-picker">
        <span class="demonstration">{{ label2 }}</span>
        <el-date-picker
          v-model="value1"
          type="date"
          placeholder="选择日期"
        />
    </div>
  </template>
  
  <script setup>
  import { ref,defineProps } from 'vue'
  const value1 = ref('')

  const props = defineProps({
    label2: {
      type: String,
      default: 't2'
    }
  })
  </script>
  
  <style lang="scss" scoped>
  .demo-date-picker {
    display: flex;
    justify-content: flex-end;
    height: 33px;
    span {
      margin-right: 10px;
      line-height: 30px;
    }
    :deep(.el-input) {
      width: 300px;
    }
    :deep(.el-input__wrapper) {
      width: 300px;
    }
  }
  </style>
  