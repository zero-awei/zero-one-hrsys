<script setup>
import Education from './employee/Education.vue'
import Experience from './employee/Experience.vue'
import Employee from './employee/Employee.vue'
import RewardsAndPunishment from './employee/RewardsAndPunishment.vue'
import Additional from './employee/Additional.vue'
import Edit from '@/components/edit/Edit.vue'
</script>

<template>
  <div class="employeeInfo">
    <div class="title">
      <div class="titleInfo">员工信息</div>
      <div class="edit">
        <Edit />
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
