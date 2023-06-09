<template>
  <div>
    <el-button plain @click="dialogFormVisible = true">
      <span  class="hr-button">
          <IconDocument class="hr-button__icon"/>
          <p class="hr-button__p">
            新增
          </p>
      </span>
    </el-button>
      <el-dialog v-model="dialogFormVisible" :title="addTitle" :close-on-click-modal="false" width="440px">
        <div class="line"></div>
        <div class="hr-dialog-head">
          <span class="dialog-header">
            <el-button @click="addTableData(saveData)">
              <span  class="hr-button">
              <IconChecked class="hr-button__icon"/>
              <p class="hr-button__p">
                <!-- Confirm -->
                确认
              </p>
              </span>
            </el-button>
            <el-button @click="dialogFormVisible = false">
              <span  class="hr-button">
              <IconFailed class="hr-button__icon"/>
              <p class="hr-button__p">
                退出
              </p>
              </span>
            </el-button>
          </span>
        </div>
        <div class="hr-dialog-body">
          <el-form v-model="formData">
            <div v-for="data in dataitem" :key="data.name">
              <el-form-item  :label="data.label" :label-width="formLabelWidth" >
                    <el-select v-model="formData[data.name]" placeholder="请选择..." v-if="data.type===Array">
                      <el-option v-for="option in data.options" :key="option.id" :label="option.optionData" :value="option.optionData" />
                    </el-select>
                    <el-input
                      v-model="formData[data.name]"
                      :rows="2"
                      type="textarea"
                      placeholder="请输入"
                      v-else-if="data.type === 'Text'"
                    />
                    <el-input v-model="formData[data.name]" autocomplete="off" v-else/>
              </el-form-item>
            </div>
          </el-form>
        </div>
      </el-dialog>
    </div>
</template>

<script setup>

const dialogTableVisible = ref(false)
const dialogFormVisible = ref(false)
const formLabelWidth = '140px'

defineProps({
    tableTitle : String,
    addTitle : String,
    dataitem : Array,
    saveData: Function
  })

const formData = ref({})

const addTableData = (saveData) =>{
  saveData(formData.value)
  dialogFormVisible.value = false
  formData.value={}
}
</script>

<style lang="scss" scoped>
.hr-dialog-head{
    display:flex;
    justify-content:right;
}
.hr-dialog-body{
    display:flex;
    justify-content:right;
}
.hr-button{
  display:flex;
  @include element(icon){
    width: 14px;
    height: 16px;
    margin-right: 6px;
  }
  @include element(p){
    font-size: 14px;
    margin-top: 1.5px;
  }
}

.el-button{
  width: 60px;
  height: 32px;
  padding: 0 6px;
  border: 0;
}
.el-button--text {
  width: 64px;
  height: 32px;
  margin-right: 15px;
}
.el-select {
  width: 250px;
}
.el-input {
  width: 250px;
}
.dialog-header button:first-child {
  margin-right: 10px;
}
.line{
  position:relative;
  bottom:20px;
  height: 1px;
  background-color: #545454;
  opacity: 0.1;
}
</style>