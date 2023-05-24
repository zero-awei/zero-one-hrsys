<template>
  <el-button type="default" style="margin-left: 16px" @click="drawer = true">
    编辑
  </el-button>

  <el-drawer
    v-model="drawer"
    title=""
    :direction="direction"
    :before-close="handleClose"
    class="el-drawer"
    size="71%"
  >
    <div class="d1">
      <span>员工信息</span>
      <div class="edit1">
        <div class="left">
          <EditPrimary label1="员工编号">
            <template v-slot:t1>
              <span style="color: red; line-height: 30px; margin-right: 10px"
                >*</span
              >
            </template>
          </EditPrimary>
          <EditPrimary label1="员工姓名">
            <template v-slot:t1>
              <span style="color: red; line-height: 30px; margin-right: 10px"
                >*</span
              >
            </template>
          </EditPrimary>
          <EditOptions>
            <template v-slot:t3>
              <span style="color: red; line-height: 30px; margin-right: 10px"
                >*</span
              >
            </template>
            <template v-slot:t3-a>
              <span style="margin-right: 10px; line-height: 31px"
                >证件类型</span
              >
            </template>
          </EditOptions>
          <EditPrimary label1="证件号码">
            <template v-slot:t1>
              <span style="color: red; line-height: 30px; margin-right: 10px"
                >*</span
              >
            </template>
          </EditPrimary>
          <EditDate label2="出生日期"></EditDate>
          <EditPrimary label1="年龄"></EditPrimary>
          <EditOptions label3="性别"></EditOptions>
          <EditOptions label3="血型">
            <template v-slot:t3-a>
              <span style="margin-right: 10px; line-height: 31px">血型</span>
            </template>
          </EditOptions>
          <EditPrimary label1="手机号码">
            <template v-slot:t1>
              <span style="color: red; line-height: 30px; margin-right: 10px"
                >*</span
              >
            </template>
          </EditPrimary>
          <EditPrimary label1="电子邮箱"></EditPrimary>
          <EditOptions label3="民族">
            <template v-slot:t3-a>
              <span style="margin-right: 10px; line-height: 31px">民族</span>
            </template>
          </EditOptions>
          <EditOptions label3="户口类型">
            <template v-slot:t3-a>
              <span style="margin-right: 10px; line-height: 31px"
                >户口类型</span
              >
            </template>
          </EditOptions>
          <EditOptions label3="户籍所在地">
            <template v-slot:t3-a>
              <span style="margin-right: 10px; line-height: 31px"
                >户籍所在地</span
              >
            </template>
          </EditOptions>
          <EditAutocomplete label4="户籍地址"></EditAutocomplete>
          <EditAutocomplete label4="通讯地址"></EditAutocomplete>
          <EditOptions label3="有独生子女证">
            <template v-slot:t3-a>
              <span style="margin-right: 10px; line-height: 31px"
                >有独生子女证</span
              >
            </template>
          </EditOptions>
          <EditPrimary label1="健康状况"></EditPrimary>
        </div>
        <div class="right">
          <EditImage></EditImage>
          <div class="right-a">
            <EditOptions>
              <template v-slot:t3-a>
                <span style="margin-right: 10px; line-height: 31px"
                  >婚姻状况</span
                >
              </template>
            </EditOptions>
            <EditAutocomplete label4="籍贯"></EditAutocomplete>
            <EditAutocomplete label4="出生地"></EditAutocomplete>
            <EditPrimary label1="爱好特长"></EditPrimary>
          </div>
        </div>
      </div>
    </div>

    <div class="d2">
      <span>政治面貌</span>
      <hr />
      <div class="edit2">
        <EditOptions>
          <template v-slot:t3-a>
            <span style="margin-right: 10px; line-height: 31px">政治面貌</span>
          </template>
        </EditOptions>
      </div>
    </div>

    <div class="d3">
      <span>职务相关</span>
      <hr />
      <div class="edit3">
        <EditOptions>
          <template v-slot:t3>
            <span style="color: red; line-height: 30px; margin-right: 10px"
              >*</span
            >
          </template>
          <template v-slot:t3-a>
            <span style="margin-right: 10px; line-height: 31px">员工状态</span>
          </template>
        </EditOptions>
        <EditOptions>
          <template v-slot:t3-a>
            <span style="margin-right: 10px; line-height: 31px">工作状态</span>
          </template>
        </EditOptions>
        <EditOptions>
          <template v-slot:t3-a>
            <span style="margin-right: 10px; line-height: 31px">入职渠道</span>
          </template>
        </EditOptions>
        <EditDate label2="参加工作时间"></EditDate>
        <EditDate label2="到本单位时间"></EditDate>
      </div>
    </div>

    <div class="d4">
      <span>其他信息</span>
      <hr />
      <div class="edit4">
        <EditOptions>
          <template v-slot:t3-a>
            <span style="margin-right: 10px; line-height: 31px"
              >列入黑名单</span
            >
          </template>
        </EditOptions>
      </div>
    </div>
  </el-drawer>
</template>

<script setup>
import EditPrimary from './EditPrimary.vue'
import EditImage from './EditImage.vue'
import EditOptions from './EditOptions.vue'
import EditDate from './EditDate.vue'
import EditAutocomplete from './EditAutocomplete.vue'

const drawer = ref(false)
const direction = ref('rtl')
</script>

<style lang="scss" scoped>
.edit1 {
  display: flex;
  justify-content: space-between;
  .left {
    margin-top: 20px;
    display: grid;
    grid-template-columns: repeat(2, 1fr);
    grid-template-rows: repeat(3, 1fr);
    gap: 30px 0;
  }
  .right {
    height: 473px;
    margin-top: 20px;
    display: flex;
    flex-direction: column;
    justify-content: space-between;
    align-items: center;
    .right-a {
      height: 218px;
      display: flex;
      flex-direction: column;
      align-items: flex-end;
      justify-content: space-between;
    }
  }
}
.d2 {
  margin-top: 20px;
  .edit2 {
    display: flex;
    justify-content: flex-start;
    align-items: center;
    height: 100px;
    padding-left: 60px;
  }
}

.d3 {
  // margin-top: 20px;
  .edit3 {
    margin-top: 20px;
    display: grid;
    grid-template-columns: repeat(3, 1fr);
    gap: 30px;
  }
}

.d4 {
  margin-top: 20px;
  .edit4 {
    margin-top: 20px;
    display: flex;
    justify-content: flex-start;
    padding-left: 40px;
  }
}
</style>
