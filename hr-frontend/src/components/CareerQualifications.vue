<template>
  <div class="chart-container">
    <h1>{{ title }}</h1>

    <el-table :data="data" :show-header="false" border style="width: 100%">
      <el-table-column prop="name" align="center" width="" />
      <el-table-column prop="color" align="center" width="">
        <template #default="scope">
          <div
            class="bar"
            :style="{
              backgroundColor: scope.row.color,
              width: (scope.row.val / total) * 100 + '%'
            }"
          >
            {{}}
          </div>
        </template>
      </el-table-column>
      <el-table-column prop="val" align="center" width="">
        <template #default="scope">
          {{ scope.row.val + '人' }}
        </template>
      </el-table-column>
    </el-table>
  </div>
</template>

<script setup>
const props = defineProps({
  title: String,
  data: {
    type: Array,
    default: () => []
  }
})

// 计算总和
let total = ref(0)
total = props.data.reduce((all, cur) => {
  return all + cur.val
}, 0)
</script>

<style lang="scss" scoped>
h1 {
  font-size: 20px;
  font-weight: bold;
}
.chart-container {
  width: 100%;
  display: flex;
  float: right;
  flex-direction: column;
  align-items: flex-start;
}

.row {
  display: flex;
  align-items: center;
  margin-bottom: 10px;
}

.job-type {
  font-weight: normal;
  margin-right: 10px;
}

.bar-container {
  display: flex;
  align-items: center;
  width: 100%;
  background-color: transparent;
  overflow: hidden;
}

.bar {
  border-radius: 5px;
  height: 20px;
  background-color: var(--bar-color);
  transition: width 0.3s ease-in-out;
}
/* 通过bar-width控制柱状图的宽度，bar-color控制柱状图的颜色 值是count×2px的结果*/
.count {
  font-size: 14px;
  padding-left: 4px;
  /* margin-right: auto; */
}
</style>
