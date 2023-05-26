<template>
  <div class="input-options">
    <el-form class="f1" :model="form">
      <slot name="t3"></slot>
      <slot name="t3-a"></slot>
      <el-form-item>
        <el-select v-model="form.region" placeholder="" style="width: 300px">
          <el-option label="身份证" value="身份证" />
          <el-option label="护照" value="护照"/>
          <el-option label="其他" value="其他"/>
        </el-select>
      </el-form-item>
    </el-form>
  </div>
</template>

<script setup>
const form = reactive({
  name: '',
  region: '选择',
  date1: '',
  date2: '',
  delivery: false,
  type: [],
  resource: '',
  desc: '',
})
</script>

<style lang="scss" scoped>
.input-options {
  height: 33px;
  .f1 {
    display: flex;
    justify-content: flex-end;
    height: 33px;
    span {
        color: red;
        margin-right: 10px;
    }
  }
}
</style>
