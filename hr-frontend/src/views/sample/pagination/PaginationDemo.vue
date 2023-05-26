<template>
  <Pagination :pageSizes="pageSizes" :total="total"></Pagination>
</template>

<script>
import Pagination from '@/components/pagination/Pagination.vue'
export default {
  data() {
    return {
      pageSizes: ['10', '20'],
      total: 1000
    }
  },
  methods: {
    confirm() {
      console.log('value', this.value)
    }
  }
}
</script>

<style scoped></style>
