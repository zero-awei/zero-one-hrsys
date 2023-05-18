<template>
    <el-button @click="IsshowFilter = !IsshowFilter">过滤</el-button>
    <el-form
      class="filter-bar"
      v-show="IsshowFilter"
      inline="true"
      label-position="right"
    >
      <form-item
        v-for="(item, index) in info.itemArr"
        :key="index"
        class="filter-items"
      >
        <el-form-item :label="item.name" v-if="typeof item.val === 'string'">
          <el-input placeholder="" />
        </el-form-item>
  
        <el-form-item :label="item.name" v-if="typeof item.val === 'object'">
          <el-select placeholder="请选择...">
            <el-option
              v-for="(context, idx) in item.val"
              :label="context"
              :value="context"
              :key="idx"
            />
          </el-select>
        </el-form-item>
      </form-item>
    </el-form>
  </template>
  
  <script>
  import { ref } from "vue";
  export default {
    setup() {
      const IsshowFilter = ref(false);
  
      const info = {
        itemArr: [
          {
            name: "组织",
            val: ["成都分公司", "蓝海"],
          },
          {
            name: "姓名",
            val: "",
          },
          {
            name: "证件号码",
            val: "",
          },
        ],
      };
  
      return {
        info,
        IsshowFilter,
      };
    },
  };
  </script>
  
  <style scoped></style>
  