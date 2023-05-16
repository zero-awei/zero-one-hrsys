<template>
    <div class="process-bar">
      <el-steps
        :active="currentStep"
        process-status="process"
        finish-status="success"
      >
        <el-step v-for="(val, index) in stepsArr" :key="index" :title="val" />
      </el-steps>
    </div>
  </template>
  
  <script>
  export default {
    name: "Process",
    props: {
      currentStep: {
        type: Number,
        default: 0,
      },
      stepsArr: {
        type: Array,
        default: () => [],
      },
    },
    data() {
      return {};
    },
  };
  </script>
  
  <style scoped>
  .process-bar {
    padding: 10px 50px;
    border-bottom: 1px solid #ddd;
    margin-bottom: 10px;
  }
  .process-bar:deep(.el-step__title.is-wait) {
    color: rgb(192, 196, 204);
  }
  .process-bar:deep(.el-step__title.is-process) {
    color: rgb(126, 129, 135);
  }
  .process-bar:deep(.el-step__head.is-process) {
    color: rgb(126, 129, 135);
    border-color: rgb(126, 129, 135);
  }
  .process-bar:deep(.el-step__line) {
    background-color: rgb(192, 196, 204);
  }
  </style>