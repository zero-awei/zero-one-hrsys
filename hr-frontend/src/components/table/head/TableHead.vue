<template>
  <div class="hr-table-header">
    
    <div class="hr-table-header__title">{{ tableTitle }}</div>
    <slot></slot>
    <div
      class="hr-table-header__menus"
      v-for="tableOperation in tableOperations"
      :key="tableOperation.name"
    >
      <AddButton
        :tableTitle="tableTitle"
        :addTitle="addTitle"
        :addData="addData"
        v-if="tableOperation.name === '新增'"
      />
    </div>
  </div>
</template>

<script setup>
import AddButton from './AddButton.vue'

defineProps(['tableTitle', 'addTitle', 'tableOperations', 'addData'])
</script>

<style lang="scss" scoped>
.hr-table-header {
  width: 100%;
  height: 40px;
  padding: 0 10px 10px 10px;
  @include element(title) {
    float: left;
    width: 64px;
    height: 32px;
    font-size: 16px;
    font-weight: 600;
  }
  @include element(menus) {
    float: right;
    height: 100%;
  }
}
</style>