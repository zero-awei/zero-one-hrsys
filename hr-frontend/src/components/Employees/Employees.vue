<script>
// import Edit from '@element-plus/icons-vue'
import Education from './Employee/Education.vue'
import Experience from './Employee/Experience.vue'
import Employee from './Employee/Employee.vue'
import RewardsAndPunishment from './Employee/RewardsAndPunishment.vue'
import additional from './Employee/additional.vue'

export default {
  components: {
    RewardsAndPunishment,
    Experience,
    Education,
    Employee,
    additional
  }
}
</script>

<template>
  <div>
    <div class="title">
      员工信息
      <el-button class="edit" type="primary" :icon="Edit">编辑</el-button>
    </div>
    <div class="info">
      <Employee />
      <Education />
      <Experience />/
      <additional />
      <RewardsAndPunishment />
    </div>
  </div>
</template>

<style>
.title {
  position: fixed;
  top: 0;
  color: #000;
  height: 50px;
  width: 100%;
  line-height: 50px;
  font-size: 16px;
  font-weight: 600;
  background-color: #fff;
  border-bottom: 1px solid #ebeef5;
  z-index: 2;
}
.info {
  padding-top: 55px;
  margin: 30px;
}
.edit {
  position: absolute;
  right: 30px;
  top: 10px;
}
</style>
