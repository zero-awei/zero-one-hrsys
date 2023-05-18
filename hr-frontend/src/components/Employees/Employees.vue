<script>
import Education from './employee/Education.vue'
import Experience from './employee/Experience.vue'
import Employee from './employee/Employee.vue'
import RewardsAndPunishment from './employee/RewardsAndPunishment.vue'
import Additional from './employee/Additional.vue'

export default {
  components: {
    RewardsAndPunishment,
    Experience,
    Education,
    Employee,
    Additional
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
      <Additional />
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
