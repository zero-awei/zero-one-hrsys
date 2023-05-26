<template>
  <div class="additional">
    <div class="head">补充信息</div>
    <el-row class="elRow">
      <el-col :xs="24" :sm="12" :md="12" :lg="8" :xl="8">
        <div class="right">户口类型</div>
        <div class="left">
          {{ additionalInfo.householdRegistrationType }}
        </div>
      </el-col>
      <el-col :xs="24" :sm="12" :md="12" :lg="8" :xl="8">
        <div class="right">户籍所在地</div>
        <div class="left">{{ additionalInfo.domicile }}</div>
      </el-col>
      <el-col :xs="24" :sm="12" :md="12" :lg="8" :xl="8">
        <div class="right">出生地</div>
        <div class="left">{{ additionalInfo.birthplace }}</div>
      </el-col>
    </el-row>
    <el-row class="elRow">
      <el-col :xs="24" :sm="12" :md="12" :lg="8" :xl="8">
        <div class="right">健康状况</div>
        <div class="left">{{ additionalInfo.healthCondition }}</div>
      </el-col>
      <el-col :xs="24" :sm="12" :md="12" :lg="8" :xl="8">
        <div class="right">爱好特长</div>
        <div class="left">{{ additionalInfo.hobbies }}</div>
      </el-col>
      <el-col :xs="24" :sm="12" :md="12" :lg="8" :xl="8">
        <div class="right">血型</div>
        <div class="left">{{ additionalInfo.BloodType }}</div>
      </el-col>
    </el-row>
    <el-row class="elRow">
      <el-col :xs="24" :sm="12" :md="12" :lg="8" :xl="8">
        <div class="right">有独生子女证</div>
        <div class="left">{{ additionalInfo.isOnlyChild }}</div>
      </el-col>
      <el-col :xs="24" :sm="12" :md="12" :lg="8" :xl="8">
        <div class="right">通讯地址</div>
        <div class="left">{{ additionalInfo.mailingAddress }}</div>
      </el-col>
      <el-col :xs="24" :sm="12" :md="12" :lg="8" :xl="8">
        <div class="right">入职渠道</div>
        <div class="left">{{ additionalInfo.entryChannel }}</div>
      </el-col>
    </el-row>
    <el-row class="elRow">
      <el-col :xs="24" :sm="12" :md="12" :lg="8" :xl="8">
        <div class="right">员工状态</div>
        <div class="left">{{ additionalInfo.employeeStatus }}</div>
      </el-col>
      <el-col :xs="24" :sm="12" :md="12" :lg="8" :xl="8">
        <div class="right">列入黑名单</div>
        <div class="left">{{ additionalInfo.blacklisted }}</div>
      </el-col>
    </el-row>
    <!-- <div class="box h2">
     
    </div> -->
  </div>
</template>
<script setup>
import { inject } from 'vue'
const userData = inject('userData')
let { additionalInfo } = userData
</script>
<style scoped>
.additional {
  padding: 12px 0 10px 16px;
}
.head {
  padding: 0 10px 10px 10px;
  color: #000;
  height: 50px;
  line-height: 50px;
  font-size: 16px;
  font-weight: 600;
  border-bottom: 1px solid #d8dae0;
}
.box {
  display: flex;
  height: 200px;
}

.box div {
  flex: 1;
  height: 50px;
}
.left {
  padding-left: 8px;
  float: left;
  text-align: left;
}
.right {
  float: left;
  width: 133px;
  text-align: right;
  padding-right: 6px;
}
.elRow {
  height: auto;
  min-height: 60px;
}
.el-col {
  margin-bottom: 20px;
}
</style>
