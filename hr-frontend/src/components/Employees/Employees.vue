<script setup>
import Education from './Employee/Education.vue'
import Experience from './Employee/Experience.vue'
import Employee from './Employee/Employee.vue'
import RewardsAndPunishment from './Employee/RewardsAndPunishment.vue'
import Additional from './Employee/Additional.vue'
</script>

<template>
  <div class="employeeInfo">
    <div class="title">
      <div class="titleInfo">员工信息</div>
      <div class="edit">
        <el-icon :size="size" :color="color" class="icon">
          <Edit />
        </el-icon>
        <span>编辑</span>
      </div>
    </div>
    <div class="info">
      <Employee />
      <Education />
      <Experience />
      <Additional />
      <RewardsAndPunishment />
    </div>
  </div>
</template>

<style scoped lang="scss">
.employeeInfo {
  width: 100%;
  height: 95vh;
}
.title {
  display: flex;
  justify-content: space-between;
  align-items: baseline;
  position: fixed;
  top: 5vh;
  width: calc(100% - 220px);
  height: 50px;
  background-color: #edecec;
  padding: 0 10px 10px 10px;
  border-bottom: 1px solid #d8dae0;
  z-index: 1;
  .titleInfo {
    color: #000;
    line-height: 50px;
    font-size: 16px;
    font-weight: 600;
  }
  .edit {
    width: 100px;
    line-height: 24px;
    z-index: 1;
    cursor: pointer;
  }
  .icon {
    vertical-align: middle;
    padding-right: 5px;
  }
}
.info {
  width: 100%;
  height: calc(100% - 40px);
  padding-top: 38px;
}
</style>
