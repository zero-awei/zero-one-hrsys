<template>
  <el-button type="default" @click="drawer = true">
    <el-icon class="icon">
      <Edit />
    </el-icon>
    <span>编辑</span>
  </el-button>

  <el-drawer
    v-model="drawer"
    :direction="direction"
    :before-close="handleClose"
    class="el-drawer"
    size="50%"
    :z-index="10"
  >
    <el-form
      :inline="true"
      :model="formEdit"
      class="demo-form-inline"
      ref="ruleForFormEdit"
    >
      <div class="title">员工信息</div>
      <el-row>
        <el-col class="elCol" :span="8">
          <el-row :span="8" class="elRow">
            <el-form-item label="员工编号">
              <el-input v-model="formEdit.empno" />
            </el-form-item>
          </el-row>
          <el-row :span="8" class="elRow">
            <el-form-item label="证件类型">
              <el-input v-model="formEdit.IDType" />
            </el-form-item>
          </el-row>
          <el-row :span="8" class="elRow">
            <el-form-item label="出生日期">
              <el-input v-model="formEdit.birth" />
            </el-form-item>
          </el-row>
          <el-row :span="8" class="elRow">
            <el-form-item label="性别">
              <el-input v-model="formEdit.birth" />
            </el-form-item>
          </el-row>
        </el-col>
        <el-col class="elCol" :span="8">
          <el-row :span="8" class="elRow">
            <el-form-item label="员工姓名">
              <el-input v-model="formEdit.ename" />
            </el-form-item>
          </el-row>
          <el-row :span="8" class="elRow">
            <el-form-item label="证件号码">
              <el-input v-model="formEdit.IDNumber" />
            </el-form-item>
          </el-row>
          <el-row :span="8" class="elRow">
            <el-form-item label="年龄">
              <el-input v-model="formEdit.age" />
            </el-form-item>
          </el-row>
          <el-row :span="8" class="elRow">
            <el-form-item label="血型">
              <el-input v-model="formEdit.BloodType" />
            </el-form-item>
          </el-row>
        </el-col>
        <el-col class="elCol" :span="8">
          <el-row :span="8" class="elRow">
            <el-form-item label="照片">
              <el-avatar
                class="elAvatar"
                shape="square"
                :size="100"
                fit="fit"
                :src="basicInfo.url"
              />
            </el-form-item>
          </el-row>
        </el-col>
      </el-row>
      <!-- 第二个表格 -->
      <el-row>
        <el-col class="elCol" :span="8">
          <el-row :span="8" class="elRow">
            <el-form-item label="手机号码">
              <el-input v-model="formEdit.mobileNumber" />
            </el-form-item>
          </el-row>
          <el-row :span="8" class="elRow">
            <el-form-item label="民族">
              <el-input v-model="formEdit.nation" />
            </el-form-item>
          </el-row>
          <el-row :span="8" class="elRow">
            <el-form-item label="户籍所在地">
              <el-input v-model="formEdit.domicile" />
            </el-form-item>
          </el-row>
          <el-row :span="8" class="elRow">
            <el-form-item label="通讯地址">
              <el-input v-model="formEdit.mailingAddress" />
            </el-form-item>
          </el-row>
          <el-row :span="8" class="elRow">
            <el-form-item label="健康状况">
              <el-input v-model="formEdit.healthCondition" />
            </el-form-item>
          </el-row>
        </el-col>
        <el-col class="elCol" :span="8">
          <el-row :span="8" class="elRow">
            <el-form-item label="电子邮箱">
              <el-input v-model="formEdit.eMail" />
            </el-form-item>
          </el-row>
          <el-row :span="8" class="elRow">
            <el-form-item label="户口类型">
              <el-input v-model="formEdit.householdRegistrationType" />
            </el-form-item>
          </el-row>
          <el-row :span="8" class="elRow">
            <el-form-item label="户籍地址">
              <el-input v-model="formEdit.domicile" />
            </el-form-item>
          </el-row>
          <el-row :span="8" class="elRow">
            <el-form-item label="有独生子女证">
              <el-input v-model="formEdit.isOnlyChild" />
            </el-form-item>
          </el-row>
        </el-col>
        <el-col class="elCol" :span="8">
          <el-row :span="8" class="elRow">
            <el-form-item label="婚姻状况">
              <el-input v-model="formEdit.marriage" />
            </el-form-item>
          </el-row>
          <el-row :span="8" class="elRow">
            <el-form-item label="籍贯">
              <el-input v-model="formEdit.birthplace" />
            </el-form-item>
          </el-row>
          <el-row :span="8" class="elRow">
            <el-form-item label="出生地">
              <el-input v-model="formEdit.birthplace" />
            </el-form-item>
          </el-row>
          <el-row :span="8" class="elRow">
            <el-form-item label="爱好特长">
              <el-input v-model="formEdit.hobbies" />
            </el-form-item>
          </el-row>
        </el-col>
      </el-row>
      <div class="title">政治面貌</div>
      <el-col class="elCol" :span="8">
        <el-row :span="8" class="elRow">
          <el-form-item label="政治面貌">
            <el-input v-model="formEdit.politicalLandscape" />
          </el-form-item>
        </el-row>
      </el-col>
      <div class="title">职务相关</div>
      <el-row>
        <el-col class="elCol" :span="8">
          <el-row :span="8" class="elRow">
            <el-form-item label="员工状态">
              <el-input v-model="formEdit.employeeStatus" />
            </el-form-item>
          </el-row>
          <el-row :span="8" class="elRow">
            <el-form-item label="参加工作时间">
              <el-input v-model="formEdit.cjgzsj" />
            </el-form-item>
          </el-row>
        </el-col>
        <el-col class="elCol" :span="8">
          <el-row :span="8" class="elRow">
            <el-form-item label="工作状态">
              <el-input v-model="formEdit.employeeStatus" />
            </el-form-item>
          </el-row>
          <el-row :span="8" class="elRow">
            <el-form-item label="到本单位时间">
              <el-input v-model="formEdit.unitTime" />
            </el-form-item>
          </el-row>
        </el-col>
        <el-col class="elCol" :span="8">
          <el-row :span="8" class="elRow">
            <el-form-item label="入职渠道">
              <el-input v-model="formEdit.entryChannel" />
            </el-form-item>
          </el-row>
        </el-col>
      </el-row>
      <div class="title">其他信息</div>
      <el-col class="elCol" :span="8">
        <el-row :span="8" class="elRow">
          <el-form-item label="列入黑名单">
            <el-input v-model="formEdit.blacklisted" />
          </el-form-item>
        </el-row>
      </el-col>
    </el-form>
  </el-drawer>
</template>

<script setup>
const drawer = ref(false)
const direction = ref('rtl')
const userData = inject('userData')
let { basicInfo, additionalInfo } = userData
const formEdit = reactive({ ...basicInfo, ...additionalInfo })
const onSubmit = async (formEl) => {
  if (!formEl) return
  console.log(formEdit)
  //   await formEl.validate((valid, fields) => {
  //     if (valid) {
  //       console.log(formEdit)
  //     } else {
  //       console.log('error submit!', fields)
  //     }
  //   })
}

const handleClose = (done) => {
  done()
}
</script>

<style lang="scss" scoped>
.title {
  font-size: 16px;
  color: #000;
  font-weight: 600;
}
</style>
