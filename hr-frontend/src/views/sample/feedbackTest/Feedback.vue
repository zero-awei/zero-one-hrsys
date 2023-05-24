<template>
  <!--  1.消息弹出框演示 -->
  <MessageBox></MessageBox>
  <div>
    <el-table :data="tableData" style="width: 100%" @cell-click="changeMessage">
      <el-table-column prop="date" label="Date" width="180" />
      <el-table-column prop="name" label="Name" width="180" />
      <el-table-column prop="action" label="Action"/>
    </el-table>
  </div>

  <br/>
  <!-- 2.消息提示演示 -->
  <Notification></Notification>
  <el-row class="mb-4">
    <el-button type="success" @click="changeValue">保存成功</el-button>
    <el-button type="warning" @click="changeValueThree">未配置导入项--警告</el-button>
    <el-button type="danger" @click="changeValueTwo">输入项为空--出错</el-button>
  </el-row>
</template>

<script setup>
import MessageBox from '@/components/feedback/MessageBox.vue'
import Notification from '@/components/feedback/Notification.vue'

//1.消息弹出框演示
const tableData = [
  {
    date: '2016-05-03',
    name: 'Tom',
    action: 'No. 189, Grove St, Los Angeles'
  },
  {
    date: '2016-05-02',
    name: 'Tom',
    action: 'No. 189, Grove St, Los Angeles'
  },
  {
    date: '2016-05-04',
    name: 'Tom',
    action: 'No. 189, Grove St, Los Angeles'
  },
  {
    date: '2016-05-01',
    name: 'Tom',
    action: 'No. 189, Grove St, Los Angeles'
  }
]

let messageInfo = ref('确定删除吗？')
let messageSuccess = ref('删除成功')
let messageError = ref('取消')
let message = reactive({ messageInfo, messageSuccess, messageError })

//点击按钮，向公共组件发消息
const mitt = getCurrentInstance().appContext.config.globalProperties.$bus
const changeMessage = (row, column) => {
  console.log(row)
  //点击某一列执行，利用column中的label属性，例如点击Action这一列
  if (column.label === 'Action') {
    //执行逻辑
    mitt.emit('changeInfo', message)
  }
}

//2.消息提示演示
let success = ref('成功')
let warn = ref('请配置数据导入项')
let error = ref('值规则校验异常')
let messageTwo = reactive({
  success,
  error,
  warn
})

const changeValue = () => {
  messageTwo.success = '保存成功'
  mitt.emit('showSuccess', messageTwo.success)
}

const changeValueTwo = () => {
  mitt.emit('showError', messageTwo.error)
}

const changeValueThree = () => {
  mitt.emit('showWarn', messageTwo.warn)
}
</script>
<style lang="scss" scoped></style>
