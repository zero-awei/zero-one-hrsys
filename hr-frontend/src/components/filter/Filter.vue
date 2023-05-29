<template>
  <div class="filter">
    <el-row>
      <el-col :span="20">
        <div class="filter-form">
          <el-form :model="formFilter" label-width="120px">
            <el-row>
              <el-col :span="6">
                <el-form-item label="员工姓名">
                  <el-input v-model="formFilter.employeeName" />
                </el-form-item>
              </el-col>
              <el-col :span="6">
                <el-form-item label="员工编号">
                  <el-input v-model="formFilter.employeeNum" />
                </el-form-item>
              </el-col>
              <el-col :span="6">
                <el-form-item label="证件号码">
                  <el-input v-model="formFilter.Id" />
                </el-form-item>
              </el-col>
              <el-col :span="6">
                <el-form-item label="组织">
                  <el-input v-model="formFilter.organization" />
                </el-form-item>
              </el-col>
            </el-row>

            <el-row>
              <el-col :span="6">
                <el-form-item label="部门">
                  <el-input v-model="formFilter.department" />
                </el-form-item>
              </el-col>
              <el-col :span="6">
                <el-form-item label="员工状态">
                  <el-select
                    v-model="formFilter.employeeStatus"
                    placeholder="请选择..."
                    style="width: 100%"
                  >
                    <el-option
                      v-for="item in employeeStatusOptions"
                      :key="item.value"
                      :label="item.label"
                      :value="item.value"
                    ></el-option>
                  </el-select>
                </el-form-item>
              </el-col>
              <el-col :span="6">
                <el-form-item label="在岗状态">
                  <el-select
                    v-model="formFilter.dutyStatus"
                    placeholder="请选择..."
                    style="width: 100%"
                  >
                    <el-option
                      v-for="item in dutyStatusOptions"
                      :key="item.value"
                      :label="item.label"
                      :value="item.value"
                    ></el-option>
                  </el-select>
                </el-form-item>
              </el-col>
            </el-row>
          </el-form>
        </div>
      </el-col>
      <el-col :span="4">
        <div class="filter-btn">
          <el-button type="primary" @click="search">搜索</el-button>
          <el-button @click="clearForm">重置</el-button>
        </div></el-col
      >
    </el-row>
  </div>
</template>

<script setup lang="ts">
import { reactive } from 'vue'

let formFilter = reactive({
  employeeName: '',
  employeeNum: '',
  Id: '',
  organization: '',
  department: '',
  employeeStatus: '',
  dutyStatus: ''
})

async function search() {
  // 发送网络请求
}
function clearForm() {
  const formInit = {
    employeeName: '',
    employeeNum: '',
    Id: '',
    organization: '',
    department: '',
    employeeStatus: '',
    dutyStatus: ''
  }
  formFilter = Object.assign(formFilter, formInit)
}

const employeeStatusOptions = [
  {
    value: 'on',
    label: '在职'
  },
  {
    value: 'apprenticeship',
    label: '见习'
  },
  {
    value: 'probation',
    label: '试用'
  },
  {
    value: 're-employ',
    label: '返聘'
  },
  {
    value: 'unemployed',
    label: '待岗'
  },
  {
    value: 'dismiss',
    label: '解聘'
  },
  {
    value: 'off',
    label: '离职'
  },
  {
    value: 'retire',
    label: '退休'
  },
  {
    value: 'discharge',
    label: '离休'
  },
  {
    value: 'retreat',
    label: '内退'
  },
  {
    value: 'sick',
    label: '病休'
  },
  {
    value: 'adjusted',
    label: '可调配'
  },
  {
    value: 'died',
    label: '身故'
  },
  {
    value: 'co-management',
    label: '共同管理'
  }
]

const dutyStatusOptions = [
  {
    value: 'on',
    label: '在岗'
  },
  {
    value: 'off',
    label: '离岗'
  }
]
</script>

<style lang="less" scoped>
.filter {
  background-color: #fff;
  .filter-form {
    margin: 20px;
  }
  .filter-btn {
    margin: 20px;
  }
}
</style>
