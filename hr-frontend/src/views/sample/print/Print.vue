<template>
  <div>
    <el-button type="primary" @click="executeCodePrint">代码模式打印</el-button>
    <el-button type="primary" @click="executeTplPrint">拖拽模板打印</el-button>
  </div>
</template>

<script setup>
import { onMounted } from 'vue'
import { disAutoConnect, hiprint } from 'vue-plugin-hiprint'

// 定义打印模板字符串对象
let tplJson

// 挂载的时候初始化打印对象
onMounted(async () => {
  // 取消自动连接直接打印客户端
  disAutoConnect()
  // 引入后使用示例
  hiprint.init()
  // 获取打印模板
  const req = await fetch('/template/test-print-tpl.json')
  tplJson = await req.json()
})

// 下列方法都是没有拖拽设计页面的, 相当于代码模式, 使用代码设计页面
function executeCodePrint() {
  let printTemplate = new hiprint.PrintTemplate()
  // 创建一个绘制面板
  let panel = printTemplate.addPrintPanel({
    width: 100,
    height: 130,
    paperFooter: 340,
    paperHeader: 10
  })
  // 文本
  panel.addPrintText({
    options: {
      width: 140,
      height: 15,
      top: 20,
      left: 20,
      title: '测试标题文字',
      textAlign: 'center'
    }
  })
  // 条形码
  panel.addPrintText({
    options: {
      width: 140,
      height: 35,
      top: 40,
      left: 20,
      title: '123456',
      textType: 'barcode'
    }
  })
  // 二维码
  panel.addPrintText({
    options: {
      width: 35,
      height: 35,
      top: 40,
      left: 165,
      title: '123456',
      textType: 'qrcode'
    }
  })
  // 长文本
  panel.addPrintLongText({
    options: {
      width: 180,
      height: 35,
      top: 90,
      left: 20,
      title: '( ಠ ಠ )：这是一个很长的文本(◔ д ◔)(◣_◢)'
    }
  })
  // 打印
  printTemplate.print({})
}

// 使用拖拽模板打印
function executeTplPrint() {
  let printTemplate = new hiprint.PrintTemplate({
    template: tplJson
  })
  printTemplate.print({ tname: '我是标题' })
}
</script>
