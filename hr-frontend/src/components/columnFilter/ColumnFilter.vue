<template>
  <div class="ColumnFilter">
    <div class="flex flex-wrap items-center">
      <el-dropdown trigger="click" :hide-on-click="false">
        <el-button>
          <el-icon class="el-icon--left"><Operation /></el-icon>选择列
        </el-button>
        <template #dropdown>
          <el-dropdown-menu>
            <el-dropdown-item v-for="item in xmlData" :key="item.id">
              <el-checkbox
                :label="item.name"
                v-model="checkStatus"
                @change="handleCheckboxChange"
              ></el-checkbox>
            </el-dropdown-item>
          </el-dropdown-menu>
        </template>
      </el-dropdown>
    </div>
  </div>
</template>

<script setup lang="ts">
import { ArrowDown } from '@element-plus/icons-vue'
import { PropType, ref } from 'vue'

//记录CheckBox的状态
let checkStatus = ref([])
// let newXmlData = ref([])
const props = defineProps({
  xmlData: {
    type: Array as PropType<TableCell[]>,
    default: () => []
  },
  parentMethod: {
    type: Function,
    default: () => {}
  }
})

// newXmlData.value = [...props.xmlData]
for (let i in props.xmlData) {
  checkStatus.value[i] = props.xmlData[i].name
}
console.log(checkStatus)

//表单数据定义
interface TableCell {
  id: number | string
  name: string
  prop: string
}

const handleClick = () => {
  // eslint-disable-next-line no-alert
  alert('button click')
}
function handleCheckboxChange() {
  props.parentMethod(checkStatus)
}
</script>

<style lang="scss" scoped>
.ColumnFilter {
  color: purple;
}
</style>
