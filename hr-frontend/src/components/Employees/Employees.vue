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
      <Experience />
      <Additional />
      <RewardsAndPunishment />
    </div>
  </div>
</template>

<style>
* {
  margin: 0;
  padding: 0;
}
.title {
  top: 50px;
  position: fixed;
  color: #000;
  height: 50px;
  width: 100%;
  line-height: 50px;
  font-size: 16px;
  font-weight: 600;
  background-color: #fff;
  border-bottom: 1px solid #ebeef5;
  z-index: 1;
}
.edit {
  height: 50px;
  width: 100px;
  position: absolute;
  right: 30px;
  top: 10px;
  z-index: 2;
}
.info {
  margin: 50px;
}
</style>
