<template>
    <el-button plain @click="dialogFormVisible = true">
      <span  class="hr-button">
          <IconDocument class="hr-button__icon"/>
          <p class="hr-button__p">
            新增
          </p>
      </span>
    </el-button>
    <el-dialog v-model="dialogFormVisible" :title="tableTitle" :close-on-click-modal="false">
        <span class="dialog-footer">
          <el-button @click="dialogFormVisible = false">
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
    <el-form :model="formData" >
      <div v-for="data in addData" :key="data.name">
        <el-form-item  :label="data.label" :label-width="formLabelWidth" >
              <el-input v-model="formData[data.name]" autocomplete="off" v-if="data.type!=Array"/>
              <el-select v-model="formData[data.name]" placeholder="Please select a option" v-if="data.type===Array">
                <el-option v-for="option in data.options" :key="option.id" :label="option.optionData" :value="option.optionData" />
              </el-select>
        </el-form-item>
      </div>
    </el-form>
  </el-dialog>
</template>

<script setup>
const dialogTableVisible = ref(false)
const dialogFormVisible = ref(false)
const formLabelWidth = '140px'

defineProps({
    tableTitle : String,
    addData : Array
  })

const formData = ref({
  // name: '',
  // region: '',
  // date1: '',
  // date2: '',
  // delivery: false,
  // type: [],
})


</script>

<style lang="scss" scoped>
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
  width: 300px;
}
.el-input {
  width: 300px;
}
.dialog-footer button:first-child {
  margin-right: 10px;
}
</style>