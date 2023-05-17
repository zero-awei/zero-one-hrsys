<template>
  <el-row class="tac">
    <el-col :span="4">
      <el-menu
        default-active="2"
        class="el-menu-vertical-demo"
        @open="handleOpen"
        @close="handleClose"
      >
        <el-menu-item
                v-for="(mes, index) in data"
                :key="index"
                @dblclick="dblclickHandele"
              >
                <span>{{ mes }}</span>
          </el-menu-item>
      </el-menu>
    </el-col>
  </el-row>
</template>

<script setup>
import { reactive } from 'vue';
const data = reactive(['员工信息','员工信息','员工信息','员工信息','员工信息','员工信息','员工信息']);

const handleOpen = (key, keyPath) => {
  console.log(key, keyPath)
}
const handleClose = (key,keyPath) => {
  console.log(key, keyPath)
}
</script>