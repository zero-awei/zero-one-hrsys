<template>
  <el-button text @click="drawer = true">
    <el-icon class="icon">
      <Edit />
    </el-icon>
    <span>编辑</span>
  </el-button>

  <el-drawer
    v-model="drawer"
    :direction="direction"
    class="el-drawer"
    size="53%"
    :z-index="10"
    :with-header="false"
  >
    <el-form
      :inline="true"
      :model="formEdit"
      :rules="rules"
      class="editFormInline"
      ref="ruleForFormEdit"
      label-width="130"
      size="large"
    >
      <div class="title">
        <div class="titleText">员工信息</div>
        <div class="editHeader">
          <div class="save">
            <el-button text @click="onSubmit(ruleForFormEdit)">
              <el-icon><Document /></el-icon>
              <span>保存</span>
            </el-button>
          </div>
          <div class="save" @click="saveAndClose(ruleForFormEdit)">
            <el-button text>
              <el-icon><DocumentAdd /></el-icon>
              <span>保存并关闭</span>
            </el-button>
          </div>
        </div>
      </div>
      <div class="formContent">
        <el-row class="firstRow">
          <el-col class="elCol" :span="8">
            <el-row :span="8" class="elRow">
              <el-form-item label="员工编号" prop="empno">
                <el-input v-model="formEdit.empno" />
              </el-form-item>
            </el-row>
            <el-row :span="8" class="elRow">
              <el-form-item label="证件类型" prop="IDType">
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
              <el-form-item label="员工姓名" prop="ename">
                <el-input v-model="formEdit.ename" />
              </el-form-item>
            </el-row>
            <el-row :span="8" class="elRow" prop="IDNumber">
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
              <el-form-item label="手机号码" prop="mobileNumber">
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
        <div>政治面貌</div>
        <el-col class="elCol" :span="8">
          <el-row :span="8" class="elRow">
            <el-form-item label="政治面貌">
              <el-input v-model="formEdit.politicalLandscape" />
            </el-form-item>
          </el-row>
        </el-col>
        <div>职务相关</div>
        <el-row>
          <el-col class="elCol" :span="8">
            <el-row :span="8" class="elRow">
              <el-form-item label="员工状态" prop="employeeStatus">
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
        <div>其他信息</div>
        <el-col class="elCol" :span="8">
          <el-row :span="8" class="elRow">
            <el-form-item label="列入黑名单">
              <el-input v-model="formEdit.blacklisted" />
            </el-form-item>
          </el-row>
        </el-col>
      </div>
    </el-form>
  </el-drawer>
</template>

<script setup>
const drawer = ref(false)
const direction = ref('rtl')
const ruleForFormEdit = ref()
const userData = inject('userData')
let { basicInfo, additionalInfo } = userData
const formEdit = reactive({ ...basicInfo, ...additionalInfo })
const rules = reactive({
  empno: [{ required: true, message: '员工编号 值不能为空', trigger: 'blur' }],
  ename: [{ required: true, message: '员工姓名 值不能为空', trigger: 'blur' }],
  IDType: [{ required: true, trigger: 'blur' }],
  IDNumber: [
    { required: true, message: '证件号码 值不能为空', trigger: 'blur' }
  ],
  employeeStatus: [{ required: true, trigger: 'blur' }],
  mobileNumber: [
    { required: true, message: '手机号码 值不能为空', trigger: 'blur' }
  ]
})
// 提交表格请求
const onSubmit = async (formEl) => {
  if (!formEl) return
  await formEl.validate((valid, fields) => {
    if (valid) {
      console.log(formEl)
    } else {
      console.log('error submit!', fields)
    }
  })
}

const saveAndClose = (formEl) => {
  onSubmit(formEl)
  drawer.value = false
}
</script>

<style lang="scss" scoped>
.el-drawer {
  position: relative;
}
.editFormInline {
  overflow: hidden;
}
.title {
  width: 50%;
  display: flex;
  justify-content: space-between;
  height: 60px;
  padding: 20px 10px 10px 10px;
  position: fixed;
  top: 0;
  background-color: #fff;
  z-index: 12;
  .titleText {
    font-size: 16px;
    font-weight: 600;
  }
  .editHeader {
    display: flex;
    align-items: center;
  }
}
.firstRow {
  margin-top: 50px;
}
.el-input {
  width: 300px;
}
</style>
