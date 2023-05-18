<template>
  <!-- <router-view /> -->
  <TableHead :title="title" :arrs ="arrs"/>
</template>

<script setup>
import TableHead from '@/components/table/head/table-head.vue'

const title = ref('人员列表')
const arrs = reactive([
  {
    is:true,
    name:'新增'
  }
])
</script>