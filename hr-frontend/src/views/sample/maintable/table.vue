<template>
  <el-table-column label="label" width="width" prop="prop" />
</template>

<script setup lang="ts">
defineProps({
  label: {
    type: String
  },
  prop: {
    type: String
  },
  width: {
    type: Number
  }
})
</script>

<style lang="scss" scoped></style>
