<template>
  <div class="filter">
    <el-row>
      <el-col :span="20">
        <div class="filter-form">
          <el-form :model="res" label-width="120px">
            <el-row v-for="row in ceilRows - 1" :key="row">
              <el-col :span="6" v-for="curIdx in 4" :key="curIdx">
                <el-form-item
                  :label="
                    Object.values(props.data)[(row - 1) * 4 + curIdx - 1].name
                  "
                >
                  <el-input
                    v-if="
                      Object.values(props.data)[(row - 1) * 4 + curIdx - 1]
                        .type === 'input'
                    "
                    v-model="
                      res[Object.keys(props.data)[(row - 1) * 4 + curIdx - 1]]
                    "
                  />

                  <el-select
                    v-if="
                      Object.values(props.data)[(row - 1) * 4 + curIdx - 1]
                        .type === 'select'
                    "
                    v-model="
                      res[Object.keys(props.data)[(row - 1) * 4 + curIdx - 1]]
                    "
                    placeholder="请选择..."
                    style="width: 100%"
                  >
                    <el-option
                      v-for="item in props.data[
                        Object.keys(props.data)[(row - 1) * 4 + curIdx - 1]
                      ].options"
                      :key="item.value"
                      :label="item.label"
                      :value="item.value"
                    ></el-option>
                  </el-select>
                </el-form-item>
              </el-col>
            </el-row>
            <template v-if="ceilRows !== realRows">
              <el-row>
                <el-col :span="6" v-for="curIdx in lastAttr" :key="curIdx">
                  <el-form-item
                    :label="Object.values(data)[realRows * 4 + curIdx - 1].name"
                  >
                    <el-input
                      v-if="
                        Object.values(data)[realRows * 4 + curIdx - 1].type ===
                        'input'
                      "
                      v-model="
                        res[Object.keys(props.data)[realRows * 4 + curIdx - 1]]
                      "
                    />

                    <el-select
                      v-if="
                        Object.values(props.data)[realRows * 4 + curIdx - 1]
                          .type === 'select'
                      "
                      v-model="
                        res[Object.keys(props.data)[realRows * 4 + curIdx - 1]]
                      "
                      placeholder="请选择..."
                      style="width: 100%"
                    >
                      <el-option
                        v-for="item in props.data[
                          Object.keys(props.data)[realRows * 4 + curIdx - 1]
                        ].options"
                        :key="item.value"
                        :label="item.label"
                        :value="item.value"
                      ></el-option>
                    </el-select>
                  </el-form-item>
                </el-col>
              </el-row>
            </template>
          </el-form>
        </div>
      </el-col>
      <el-col :span="4">
        <div class="filter-btn">
          <el-button type="primary" @click="search">搜索</el-button>
          <el-button @click="clearForm">重置</el-button>
        </div>
      </el-col>
    </el-row>
  </div>
</template>

<script setup>
const props = defineProps({
  data: {
    type: Object,
    default: () => {}
  }
})

let res = reactive({})
// 添加对象属性（置空）
function setAttrOfObj(obj) {
  for (let item in obj) {
    res[item] = ''
  }
}

setAttrOfObj(props.data)

// 实际行数，向下取整
let realRows = computed(() => {
  return Math.floor(Object.values(props.data).length / 4)
})

// 向上取整后的行数
let ceilRows = computed(() => {
  return Math.ceil(Object.values(props.data).length / 4)
})

// 模4剩余的属性个数
let lastAttr = computed(() => {
  return Object.values(props.data).slice(-Object.values(props.data).length % 4)
    .length
})

// 全局事件总线
const mitt = getCurrentInstance().appContext.config.globalProperties.$bus
async function search() {
  // 发送网络请求
  mitt.emit('search', res)
}
// 重置
function clearForm() {
  setAttrOfObj(props.data)
}

</script>

<style lang="scss" scoped>
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
