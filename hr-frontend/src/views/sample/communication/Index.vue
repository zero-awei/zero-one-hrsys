<template>
  <div class="hr-btns">
    <A></A>
    <B></B>
  </div>
</template>

<script setup>
import A from './A.vue'
import B from './B.vue'

</script>

<style lang="scss" scoped>
@include block(btns) {
  width: 250px;
  display: flex;
  justify-content: space-between;
  border: 2px solid #ccc;
}
</style>