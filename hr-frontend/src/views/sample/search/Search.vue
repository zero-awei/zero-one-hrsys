<template>
  <Search :filter="filter"></Search>
</template>

<script setup>
import Search from '@/components/SearchBox.vue'
const filter = (val) => {
  console.log(`output->`, val )
}
</script>

<style lang="scss" scoped></style>
