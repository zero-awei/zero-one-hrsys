<template>
  <Process ref="process" :stepsArr="stepsArr"></Process>
  <button @click="control">下一步</button>
</template>

<script>
import Process from '@/components/Process.vue'
export default {
  name: 'ProcessDemo',
  components: {
    Process
  },
  data() {
    return {
      // 进度标题
      stepsArr: ['Step 1', 'Step 2']
    }
  },
  methods: {
    // 完成任务，进入下一进度（修改子组件数据）
    control(val) {
      this.$refs.process.currentStep++
      console.log(`output->process`, this.$refs.process.currentStep)
    }
  }
}
</script>

<style lang="scss" scoped></style>
