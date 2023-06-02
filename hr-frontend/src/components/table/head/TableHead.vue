<template>
    <div class="hr-table-header">
        <div class="hr-table-header__title">{{tableTitle}}</div>
        <div class="hr-table-header__menus">
            <el-row class="row-bg" justify="end">
                  <div v-for="tableOperation in tableOperations" :key="tableOperation.name">
                    <SearchBox v-if="tableOperation.name==='搜索'"/>
                    <div style="postion:relative;top:4px">
                      <AddButton :tableTitle="tableTitle" :addTitle="addTitle" :dataitem="dataitem" :saveData="saveData" v-if="tableOperation.name==='新增'"/>
                    </div>
                  </div>
            </el-row>            
        </div>
    </div>
</template>

<script setup>
import AddButton from "./AddButton.vue"
import SearchBox from "@/components/SearchBox.vue"

defineProps(['tableTitle','addTitle','tableOperations','dataitem','saveData'])
</script>

<style lang="scss" scoped>

.hr-table-header{
    width: 100%;
    height: 40px;
    padding: 0 10px 10px 10px;
    @include element(title){
        float: left;
        width: 120px;
        height: 32px;
        font-size: 16px;
        font-weight: 600;
    }
    // @include element(menus){
    //     float: right;
    //     height: 100%;
    // }
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
