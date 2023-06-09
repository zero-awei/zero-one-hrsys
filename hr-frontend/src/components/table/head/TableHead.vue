<template>
  <div class="hr-table-header">
    <div class="hr-table-header__title">{{ tableTitle }}</div>
    <div class="hr-table-header__menus">
      <el-row class="row-bg" justify="end">
        <div
          v-for="tableOperation in tableOperations"
          :key="tableOperation.name"
        >
          <SearchBox v-if="tableOperation.name === '搜索'" :filter="filter" />
          <div style="postion: relative; top: 4px">
            <AddButton
              :tableTitle="tableTitle"
              :addTitle="addTitle"
              :dataitem="dataitem"
              :saveData="saveData"
              v-if="tableOperation.name === '新增'"
            />
            <el-button
              plain
              v-if="tableOperation.name === '删除'"
              @click="handleDeleteData(deleteData)"
            >
              <span class="hr-button">
                <IconDocument class="hr-button__icon" />
                <p class="hr-button__p">删除</p>
              </span>
            </el-button>
          </div>
        </div>
      </el-row>
    </div>
  </div>
</template>

<script setup>
import AddButton from './AddButton.vue'
import SearchBox from '@/components/SearchBox.vue'
import { getCurrentInstance, onMounted } from 'vue'
const { $bus } = getCurrentInstance().appContext.config.globalProperties

defineProps({
  tableTitle: String,
  addTitle: String,
  tableOperations:Array,
  dataitem: Array,
  saveData: Function,
  deleteData: Function,
  filter:{
    type: Function,
    default: () => {}
  }
})

//监听需要删除的数据，并将数据集传给回调函数
let ids = []
onMounted(() => {
  //监听多选数据
  $bus.on('getRowsData', (data) => {
    ids = data.value.map((item) => item)
  })
})
const handleDeleteData = (deleteData) => {
  deleteData(ids)
}
</script>

<style lang="scss" scoped>
.hr-table-header {
  width: 100%;
  height: 40px;
  padding: 0 10px 10px 10px;
  @include element(title) {
    float: left;
    width: 120px;
    height: 32px;
    font-size: 16px;
    font-weight: 600;
  }
}
.hr-button {
  display: flex;
  @include element(icon) {
    width: 14px;
    height: 16px;
    margin-right: 6px;
  }
  @include element(p) {
    font-size: 14px;
    margin-top: 1.5px;
  }
}
.el-button {
  width: 60px;
  height: 32px;
  padding: 0 6px;
  border: 0;
}
.el-button--text {
  width: 64px;
  height: 32px;
  margin-right: 15px;
}
.el-row {
  margin-bottom: 20px;
}
.el-row:last-child {
  margin-bottom: 0;
}
.el-col {
  border-radius: 4px;
}

.grid-content {
  border-radius: 4px;
  min-height: 36px;
}
</style>
