<template>
  <div class="search-container">
    <input
      class="search-input"
      type="text"
      placeholder="姓名，员工职位"
      v-model="val"
    />
    <el-icon :size="20" color="#ccc" @click="filterData"><Search /></el-icon>
  </div>
</template>

<script setup>
const props = defineProps({
  filter: {
    type: Function,
    default: () => {}
  }
})

let val = ref('')

function filterData() {
  // 这里是筛选逻辑
  props.filter(val.value.trim())
  // 在这里根据搜索内容对数据进行筛选，并执行相应的操作
}
</script>

<style lang="scss" scoped>
.search-container {
  display: flex;
  align-items: center;
  width: 300px;
  height: 40px;
  border: 1px solid #ccc;
  border-radius: 20px;
  padding: 0 10px;
}

.search-input {
  flex: 1;
  border: none;
  outline: none;
  padding: 0 10px;
}

.search-icon {
  color: gray;
  float: right;
  width: 32px;
  height: 32px;
  border-radius: 50%;
  background: transparent;
  display: flex;
  justify-content: center;
  align-items: center;
  text-decoration: none;
}
</style>
