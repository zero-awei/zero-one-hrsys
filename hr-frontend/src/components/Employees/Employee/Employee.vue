<template>
  <div class="employee">
    <div>
      <el-row>
        <el-col :xs="12" :sm="12" :md="8" :lg="8" :xl="8" class="elCol">
          <el-row :xs="12" :sm="12" :md="24" :lg="24" :xl="24" class="elRow">
            <div class="right">员工姓名</div>
            <div class="left">{{ basicInfo.ename }}</div>
          </el-row>
          <el-row :xs="12" :sm="12" :md="24" :lg="24" :xl="24" class="elRow">
            <div class="right">证件类型</div>
            <div class="left">{{ basicInfo.IDType }}</div>
          </el-row>
          <el-row :xs="12" :sm="12" :md="24" :lg="24" :xl="24" class="elRow">
            <div class="right">出生日期</div>
            <div class="left">{{ basicInfo.birth }}</div>
          </el-row>
          <el-row :xs="12" :sm="12" :md="24" :lg="24" :xl="24" class="elRow">
            <div class="right">性别</div>
            <div class="left">{{ basicInfo.sex }}</div>
          </el-row>
          <el-row :xs="12" :sm="12" :md="24" :lg="24" :xl="24">
            <div class="right">籍贯</div>
            <div class="left">{{ basicInfo.birthplace }}</div>
          </el-row>
        </el-col>
        <el-col :xs="12" :sm="12" :md="8" :lg="8" :xl="8">
          <el-row :xs="24" :sm="24" :md="24" :lg="24" :xl="24" class="elRow">
            <div class="right">员工编号</div>
            <div class="left">{{ basicInfo.empno }}</div>
          </el-row>
          <el-row :xs="24" :sm="24" :md="24" :lg="24" :xl="24" class="elRow">
            <div class="right">证件号码</div>
            <div class="left">{{ basicInfo.IDNumber }}</div>
          </el-row>
          <el-row :xs="24" :sm="24" :md="24" :lg="24" :xl="24" class="elRow">
            <div class="right">年龄</div>
            <div class="left">{{ basicInfo.age }}</div>
          </el-row>
          <el-row :xs="24" :sm="24" :md="24" :lg="24" :xl="24" class="elRow">
            <div class="right">民族</div>
            <div class="left">{{ basicInfo.nation }}</div>
          </el-row>
          <el-row :xs="24" :sm="24" :md="24" :lg="24" :xl="24" class="elRow">
            <div class="right">婚姻状况</div>
            <div class="left">{{ basicInfo.marriage }}</div>
          </el-row>
        </el-col>
        <el-col :xs="24" :sm="24" :md="8" :lg="8" :xl="8">
          <el-row :xs="24" :sm="24" :md="24" :lg="24" :xl="24">
            <div class="right">照片</div>
            <div class="left">
              <el-avatar
                class="elAvatar"
                shape="square"
                :size="100"
                fit="fit"
                :src="basicInfo.url"
              />
            </div>
          </el-row>
        </el-col>
      </el-row>
    </div>
    <div>
      <el-row class="elRow">
        <el-col :xs="24" :sm="24" :md="24" :lg="8" :xl="8" class="elCol">
          <div class="right">政治面貌</div>
          <div class="left">{{ basicInfo.politicalLandscape }}</div>
        </el-col>
        <el-col :xs="24" :sm="24" :md="24" :lg="8" :xl="8" class="elCol">
          <div class="right">职级</div>
          <div class="left">{{ basicInfo.grade }}</div>
        </el-col>
        <el-col :xs="24" :sm="24" :md="24" :lg="8" :xl="8" class="elCol">
          <div class="right">参加工作时间</div>
          <div class="left">{{ basicInfo.cjgzsj }}</div>
        </el-col>
      </el-row>
      <el-row class="elRow">
        <el-col :xs="24" :sm="24" :md="24" :lg="8" :xl="8" class="elCol">
          <div class="right">到本单位时间</div>
          <div class="left">{{ basicInfo.unitTime }}</div>
        </el-col>
        <el-col :xs="24" :sm="24" :md="24" :lg="8" :xl="8" class="elCol">
          <div class="right">手机号码</div>
          <div class="left">{{ basicInfo.mobileNumber }}</div>
        </el-col>
        <el-col :xs="24" :sm="24" :md="24" :lg="8" :xl="8" class="elCol">
          <div class="right">电子邮箱</div>
          <div class="left">{{ basicInfo.eMail }}</div>
        </el-col>
      </el-row>
      <el-row class="elRow">
        <el-col :xs="24" :sm="24" :md="24" :lg="8" :xl="8" class="elCol">
          <div class="right">技术职称</div>
          <div class="left">{{ basicInfo.technicalTitle }}</div>
        </el-col>
        <el-col :xs="24" :sm="24" :md="24" :lg="8" :xl="8" class="elCol">
          <div class="right">最高学历</div>
          <div class="left">{{ basicInfo.highestDegree }}</div>
        </el-col>
        <el-col :xs="24" :sm="24" :md="24" :lg="8" :xl="8" class="elCol">
          <div class="right">第一学历</div>
          <div class="left">{{ basicInfo.firstDegree }}</div>
        </el-col>
      </el-row>
      <el-row class="elRow">
        <el-col :xs="24" :sm="24" :md="24" :lg="8" :xl="8" class="elCol">
          <div class="right">执业证书</div>
          <div class="left">{{ basicInfo.practisingCertificate }}</div>
        </el-col>
      </el-row>
    </div>
  </div>
</template>
<script setup>
import { inject } from 'vue'
const userData = inject('userData')
let { basicInfo } = userData
</script>

<style lang="scss" scoped>
.employee {
  padding: 12px 0 10px 16px;
}
.box {
  display: flex;
}
.h2 {
  padding-top: 50px;
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
}
.elRow {
  height: auto;
  min-height: 60px;
}
.elCol {
  margin-bottom: 20px;
}
.elAvatar {
  width: 148px;
  height: 148px;
}
</style>
