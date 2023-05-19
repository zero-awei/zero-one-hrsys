<template>
    <el-button plain @click="dialogFormVisible = true">新增</el-button>
    <el-dialog v-model="dialogFormVisible" :title="tableTitle">
    <el-form :model="formData">
      <el-form-item  v-for="data in addData" :key="data.name" :label="data.label" :label-width="formLabelWidth">
        <el-input v-model="formData[data.name]" autocomplete="off" />
      </el-form-item>
      <!-- <el-form-item label="Zones" :label-width="formLabelWidth">
        <el-select v-model="form.region" placeholder="Please select a zone">
          <el-option label="Zone No.1" value="shanghai" />
          <el-option label="Zone No.2" value="beijing" />
        </el-select>
      </el-form-item> -->
    </el-form>
    <template #footer>
      <span class="dialog-footer">
        <el-button @click="dialogFormVisible = false">退出</el-button>
        <el-button type="primary" @click="dialogFormVisible = false">
          <!-- Confirm -->
          确认
        </el-button>
      </span>
    </template>
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

<style scoped>
.el-button--text {
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