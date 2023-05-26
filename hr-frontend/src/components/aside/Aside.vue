<template>
  <el-row class="tac">
    <el-col :span="3">
      <el-menu
        background-color="#fff"
        text-color="#303133"
        default-active="1"
        class="el-menu-vertical-demo"
        @open="handleOpen"
        @close="handleClose"
      >
        <el-menu-item
          v-for="(mes, index) in data"
          :key="index"
          @click="clickHandele(index)"
          :class="[{ elactive: isActive === index }, 'hr-menuitem_layout']"
        >
          <el-icon>
            <User />
            <!-- <component :is="icon" /> -->
          </el-icon>
          <span>{{ mes }}</span>
        </el-menu-item>
      </el-menu>
    </el-col>
  </el-row>
</template>

<script setup>
import { Menu as IconMenu, Location, User } from '@element-plus/icons-vue'
import { reactive, ref } from 'vue'
const isActive = ref(0)
const data = reactive([
  '员工信息',
  '分配信息',
  '教育信息',
  '语言能力',
  '家庭情况',
  '工作履历',
  '档案信息',
  '绩效信息',
  '考勤信息',
  '合同信息',
  '证书信息',
  '奖励惩罚',
  '培训记录',
  '军转干部',
  '学术成果'
])
const handleOpen = (key, keyPath) => {
  console.log(key, keyPath)
}
const handleClose = (key, keyPath) => {
  console.log(key, keyPath)
}
const clickHandele = (index) => {
  // console.log(index);
  isActive.value = index
}
</script>

<style scoped>
.el-main[data-v-3ab90702] {
  padding: 0;
}
.hr-menuitem_layout {
  height: 40px;
  line-height: 36px;
  font-size: 14px;
  color: #303133;
  padding: 0 20px;
  cursor: pointer;
  box-sizing: border-box;
  border-left: 3px solid transparent;
  border-top: 1px solid #fff;
}
.elactive {
  background: #e9e9e9 !important;
  color: #666 !important;
  border-left: 3px solid #3fd5c0;
}
</style>
